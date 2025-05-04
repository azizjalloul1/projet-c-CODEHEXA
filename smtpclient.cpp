// ===== smtpclient.cpp =====
#include "smtpclient.h"
#include <QSslSocket>
#include <QSslError>
#include <QAbstractSocket>
#include <QDebug>

SmtpClient::SmtpClient(const QString &host,
                       quint16 port,
                       const QString &user,
                       const QString &password,
                       bool useSslConn,
                       QObject *parent)
    : QObject(parent),
    smtpHost(host),
    smtpPort(port),
    smtpUser(user),
    smtpPass(password),
    useSsl(useSslConn)
{
    socket = new QSslSocket(this);

    // Logger les erreurs TLS/SSL
    connect(socket, &QSslSocket::sslErrors,
            this, [](const QList<QSslError> &errs){
                for (const auto &e : errs)
                    qDebug() << "[SMTP][SSL Error]" << e.errorString();
            });

    // Logger les erreurs de socket
    connect(socket,
            QOverload<QAbstractSocket::SocketError>::of(&QSslSocket::errorOccurred),
            this, [](QAbstractSocket::SocketError err){
                qDebug() << "[SMTP][Socket Error]" << err;
            });

    // Lecture des réponses du serveur
    connect(socket, &QSslSocket::readyRead, this, &SmtpClient::onReadyRead);
}

void SmtpClient::sendMail(const QString &from,
                          const QString &to,
                          const QString &subject,
                          const QString &body)
{
    // 1) Préparation de la file de commandes SMTP
    queue.clear();
    queue << QString("EHLO %1\r\n").arg(smtpHost)
          << "AUTH LOGIN\r\n"
          << smtpUser.toUtf8().toBase64() + "\r\n"
          << smtpPass.toUtf8().toBase64() + "\r\n"
          << QString("MAIL FROM:<%1>\r\n").arg(from)
          << QString("RCPT TO:<%1>\r\n").arg(to)
          << "DATA\r\n"
          << QString("From: %1\r\nTo: %2\r\nSubject: %3\r\n"
                     "MIME-Version: 1.0\r\n"
                     "Content-Type: text/plain; charset=\"utf-8\"\r\n\r\n")
                 .arg(from, to, subject)
          << body + "\r\n.\r\n"
          << "QUIT\r\n";

    state = HandShake;

    // 2) Réinitialiser la connexion si nécessaire
    if (socket->state() != QAbstractSocket::UnconnectedState)
        socket->abort();

    // 3) Connexion TLS immédiate (SMTPS) et handshake
    socket->connectToHostEncrypted(smtpHost, smtpPort);
    if (!socket->waitForEncrypted(15000)) {
        emit statusMessage(QString("Erreur TLS : %1")
                               .arg(socket->errorString()));
        return;
    }
    emit statusMessage("Canal SSL/TLS établi");

    // 4) Démarrer la séquence SMTP (EHLO, AUTH, MAIL, etc.)
    sendNextCommand();
}

void SmtpClient::onReadyRead()
{
    while (socket->canReadLine()) {
        QString response = socket->readLine().trimmed();
        emit statusMessage(response);

        // On ne traite que les réponses de la forme "XYZ<sep>…"
        if (response.size() < 4)
            continue;

        bool ok = false;
        int code = response.left(3).toInt(&ok);
        QChar sep = response.at(3);

        if (!ok)
            continue;

        // 221 = fin de session → on ferme la connexion
        if (code == 221) {
            socket->disconnectFromHost();
        }
        // 2xx ou 3xx (excepté 221) **et** ligne finale (sep == ' ')
        else if (code >= 200 && code < 400 && sep == ' ') {
            sendNextCommand();
        }
        // Autres codes (4xx/5xx) : on peut logger ou gérer si besoin
    }
}

void SmtpClient::sendNextCommand()
{
    if (queue.isEmpty()) return;
    QString cmd = queue.takeFirst();
    socket->write(cmd.toUtf8());
}
void SmtpClient::onConnected()  {}
void SmtpClient::onEncrypted()  {}

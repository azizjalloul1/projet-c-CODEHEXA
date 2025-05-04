#include "smtpclient.h"
#include <QSslError>
#include <QAbstractSocket>
#include <QDebug>

SmtpClient::SmtpClient(const QString &host, quint16 port,
                       const QString &user, const QString &password,
                       bool useSslConn, QObject *parent)
    : QObject(parent),
    smtpHost(host),
    smtpPort(port),
    smtpUser(user),
    smtpPass(password),
    useSsl(useSslConn)
{
    socket = new QSslSocket(this);

    // Log des erreurs SSL
    connect(socket, &QSslSocket::sslErrors,
            this, [](const QList<QSslError> &errs){
                for (const auto &e : errs)
                    qDebug() << "[SMTP][SSL Erreur]" << e.errorString();
            });

    // Log des erreurs socket
    connect(socket,
            QOverload<QAbstractSocket::SocketError>::of(&QSslSocket::errorOccurred),
            this, [](QAbstractSocket::SocketError err){
                qDebug() << "[SMTP][Socket Erreur]" << err;
            });

    // Handlers SMTP
    connect(socket, &QSslSocket::readyRead,  this, &SmtpClient::onReadyRead);
    connect(socket, &QSslSocket::connected,  this, &SmtpClient::onConnected);
    connect(socket, &QSslSocket::encrypted,  this, &SmtpClient::onEncrypted);
}

void SmtpClient::sendMail(const QString &from,
                          const QString &to,
                          const QString &subject,
                          const QString &body)
{
    // Préparation file de commandes
    queue.clear();
    queue << QString("EHLO %1\r\n").arg(smtpHost);
    if (useSsl) queue << "STARTTLS\r\n";
    queue << "AUTH LOGIN\r\n"
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

    // Si déjà connecté, on reset
    if (socket->state() != QAbstractSocket::UnconnectedState)
        socket->abort();

    // (Re)connexion
    if (useSsl)
        socket->connectToHostEncrypted(smtpHost, smtpPort);
    else
        socket->connectToHost(smtpHost, smtpPort);
}

void SmtpClient::onConnected()
{
    emit statusMessage("Connecté au serveur SMTP");
    if (!useSsl) {
        // Démarre tout de suite la séquence EHLO...
        sendNextCommand();
    }
}

void SmtpClient::onEncrypted()
{
    emit statusMessage("Canal SSL/TLS établi");
    sendNextCommand();
}

void SmtpClient::onReadyRead()
{
    while (socket->canReadLine()) {
        QString response = socket->readLine().trimmed();
        emit statusMessage(response);

        // Sur code 220,250,334,354 on passe à la commande suivante
        if (response.startsWith("220") ||
            response.startsWith("250") ||
            response.startsWith("334") ||
            response.startsWith("354")) {
            sendNextCommand();
        }
        // Sur 221, on ferme proprement
        else if (response.startsWith("221")) {
            socket->disconnectFromHost();
        }
    }
}

void SmtpClient::sendNextCommand()
{
    if (queue.isEmpty()) return;
    QString cmd = queue.takeFirst();
    socket->write(cmd.toUtf8());
}

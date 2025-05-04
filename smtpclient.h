#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QSslSocket>

class SmtpClient : public QObject
{
    Q_OBJECT
public:
    explicit SmtpClient(const QString &host,
                        quint16 port,
                        const QString &user,
                        const QString &password,
                        bool useSsl = true,
                        QObject *parent = nullptr);

    void sendMail(const QString &from,
                  const QString &to,
                  const QString &subject,
                  const QString &body);

signals:
    void statusMessage(const QString &msg);

private slots:
    void onReadyRead();
    void onConnected();
    void onEncrypted();

private:
    enum State { HandShake, Auth, Mail, Rcpt, Data, Body, Quit } state;
    QSslSocket   *socket;
    QStringList   queue;
    QString       smtpHost;
    quint16       smtpPort;
    QString       smtpUser;
    QString       smtpPass;
    bool          useSsl;

    void sendNextCommand();
};

#endif // SMTPCLIENT_H

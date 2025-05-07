#ifndef SMS_H
#define SMS_H

#include <QObject>
#include <QNetworkAccessManager>

class QNetworkReply;

class SMS : public QObject {
    Q_OBJECT

public:
    explicit SMS(const QString& accountSid,
                 const QString& authToken,
                 const QString& fromNumber,
                 QObject* parent = nullptr);

    // on garde bien ce prototype
    bool envoyerSMS(const QString& to, const QString& body);

signals:
    void envoiReussi();
    void envoiEchoue(const QString& erreur);

private slots:
    void onReplyFinished(QNetworkReply* reply);

private:
    QString m_accountSid;
    QString m_authToken;
    QString m_fromNumber;
    QNetworkAccessManager* m_manager;
};

#endif // SMS_H

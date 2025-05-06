#ifndef SMS_H
#define SMS_H

#include <QObject>

class SMS : public QObject
{
    Q_OBJECT

public:
    SMS(const QString &accountSid, const QString &authToken, const QString &fromNumber);
    bool envoyerSMS(const QString &toNumber, const QString &message);

    virtual ~SMS();  // Ajoute un destructeur virtuel

private:
    QString m_accountSid;
    QString m_authToken;
    QString m_fromNumber;
};

#endif // SMS_H

#ifndef SMS_H
#define SMS_H

#include <QString>

class SMS {
public:
    SMS(const QString& sid, const QString& token, const QString& from);

    bool envoyerSMS(const QString& to, const QString& message);

private:
    QString m_sid;
    QString m_token;
    QString m_from;
};

#endif // SMS_H

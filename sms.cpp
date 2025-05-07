#include "SMS.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

SMS::SMS(const QString& accountSid,
         const QString& authToken,
         const QString& fromNumber,
         QObject* parent)
    : QObject(parent)
    , m_accountSid(accountSid)
    , m_authToken(authToken)
    , m_fromNumber(fromNumber)
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished,
            this, &SMS::onReplyFinished);
}

bool SMS::envoyerSMS(const QString& to, const QString& body)
{
    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json")
                 .arg(m_accountSid));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/x-www-form-urlencoded");

    // Basic Auth
    QByteArray creds = (m_accountSid + ":" + m_authToken).toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + creds);

    // Corps
    QUrlQuery params;
    params.addQueryItem("To",   to);
    params.addQueryItem("From", m_fromNumber);
    params.addQueryItem("Body", body);

    m_manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
    return true;
}

void SMS::onReplyFinished(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        emit envoiReussi();
    } else {
        emit envoiEchoue(reply->errorString());
    }
    reply->deleteLater();
}

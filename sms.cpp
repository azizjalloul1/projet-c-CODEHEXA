#include "sms.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QByteArray>
#include <QObject>
#include <QDebug>

SMS::SMS(const QString &accountSid, const QString &authToken, const QString &fromNumber)
    : m_accountSid(accountSid), m_authToken(authToken), m_fromNumber(fromNumber) {}

bool SMS::envoyerSMS(const QString &toNumber, const QString &message)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + m_accountSid + "/Messages.json");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QString auth = m_accountSid + ":" + m_authToken;
    request.setRawHeader("Authorization", "Basic " + auth.toLocal8Bit().toBase64());

    QByteArray params;
    params.append("To=" + toNumber.toUtf8() + "&");
    params.append("From=" + m_fromNumber.toUtf8() + "&");
    params.append("Body=" + message.toUtf8());

    QNetworkReply *reply = manager->post(request, params);

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        return true;
    } else {
        qDebug() << "Erreur d'envoi du SMS: " << reply->errorString();
        return false;
    }
}

// Implémentation du destructeur virtuel
SMS::~SMS() {
    // Nettoyage si nécessaire (mais dans ce cas, aucun nettoyage supplémentaire n'est nécessaire)
}

#include "sms.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QEventLoop>
#include <QUrl>
#include <QByteArray>
#include <QDebug>

SMS::SMS(const QString& sid, const QString& token, const QString& from)
    : m_sid(sid), m_token(token), m_from(from) {}

bool SMS::envoyerSMS(const QString& to, const QString& message) {
    QNetworkAccessManager manager;

    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(m_sid));
    QNetworkRequest request(url);

    QString auth = m_sid + ":" + m_token;
    QByteArray data = auth.toLocal8Bit().toBase64();
    request.setRawHeader("Authorization", "Basic " + data);

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart fromPart;
    fromPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"From\""));
    fromPart.setBody(m_from.toUtf8());

    QHttpPart toPart;
    toPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"To\""));
    toPart.setBody(to.toUtf8());

    QHttpPart bodyPart;
    bodyPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"Body\""));
    bodyPart.setBody(message.toUtf8());

    multiPart->append(fromPart);
    multiPart->append(toPart);
    multiPart->append(bodyPart);

    QNetworkReply *reply = manager.post(request, multiPart);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "SMS envoyé avec succès !";
        multiPart->deleteLater();
        reply->deleteLater();
        return true;
    } else {
        qDebug() << "Erreur lors de l'envoi du SMS:" << reply->errorString();
        multiPart->deleteLater();
        reply->deleteLater();
        return false;
    }
}

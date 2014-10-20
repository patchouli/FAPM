#include "net.h"

net::net()
{

}

QString net::loadUrlContent(QUrl url){
    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest req(url);
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called
    if (reply->error() == QNetworkReply::NoError) {
        //success
        QByteArray ret = reply->readAll();
        qDebug() << "Success" << ret;
        delete reply;
        return QString(ret);
    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
        return QString("");
    }
}

QJsonObject net::loadJson(QUrl url){
    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QUrlQuery postData;
    postData.addQueryItem("i", "%7B%22f%22%3A%22func_getsimpleinfo%22%2C%22ids%22%3A%5B2415%2C10808%2C201885%2C435%2C1096%2C11491%2C100243%2C100837%2C200247%2C11734%2C11966%2C12322%2C10885%2C11191%2C200210%2C201278%2C11498%2C11501%2C11657%2C101283%2C202858%2C1915%2C2438%2C11082%2C11805%2C203602%2C12205%2C201876%2C203293%2C203593%2C361%2C12076%2C205636%5D%7D");
    postData.addQueryItem("c", "9C7D0DB8E0E276D2188193D021DCD93F");
    postData.addQueryItem("z", "1");
    postData.addQueryItem("p", "android");
    postData.addQueryItem("v", "7");
    postData.addQueryItem("cv", "17301520");
    postData.addQueryItem("chn", "home");
    postData.addQueryItem("hd", "0");
    postData.addQueryItem("uc", "2E0884EF61B7ECCD231C87FF72E5017DSM");
    QNetworkReply *reply = mgr.post(req, postData.toString(QUrl::FullyEncoded).toUtf8());
    eventLoop.exec(); // blocks stack until "finished()" has been called
    if (reply->error() == QNetworkReply::NoError) {
        //success
        QString ret = QString(reply->readAll());
        qDebug() << "Success:" << ret;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObj = jsonResponse.object();
        delete reply;
        return jsonObj;
    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
        return null;
    }
}

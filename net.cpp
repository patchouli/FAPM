#include "net.h"
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

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

#ifndef NET_H
#define NET_H
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class net
{
public:
    net();
    QString loadUrlContent(QUrl url);
    QJsonObject loadJson(QUrl url);
};

#endif // NET_H

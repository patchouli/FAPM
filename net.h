#ifndef NET_H
#define NET_H
#include <QUrl>

class net
{
public:
    net();
    QString loadUrlContent(QUrl url);
};

#endif // NET_H

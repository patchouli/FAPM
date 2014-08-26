#include "fapm.h"
#include "net.h"
#include <QApplication>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FAPM w;
    //w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    net* n = new net();
    n->loadUrlContent(QUrl(QString("http://www.baidu.com/")));
    return a.exec();
}

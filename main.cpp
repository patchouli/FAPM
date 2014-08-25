#include "fapm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FAPM w;
    w.show();

    return a.exec();
}

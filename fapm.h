#ifndef FAPM_H
#define FAPM_H

#include <QMainWindow>

namespace Ui {
class FAPM;
}

class FAPM : public QMainWindow
{
    Q_OBJECT

public:
    explicit FAPM(QWidget *parent = 0);
    ~FAPM();

private:
    Ui::FAPM *ui;
};

#endif // FAPM_H

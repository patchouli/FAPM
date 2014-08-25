#include "fapm.h"
#include "ui_fapm.h"

FAPM::FAPM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FAPM)
{
    ui->setupUi(this);
}

FAPM::~FAPM()
{
    delete ui;
}

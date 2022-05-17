#include "remind.h"
#include "ui_remind.h"

remind::remind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remind)
{
    ui->setupUi(this);
}

remind::~remind()
{
    delete ui;
}

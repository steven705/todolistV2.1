#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    QString btnStyle2 =
        "QPushButton{\
                color: rgb(255, 255, 255);\
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\
                border:1px;\
                padding:2px 4px;  \
            }\
            QPushButton:hover{\
                color: rgb(255, 255, 255); \
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(130,120,226), stop:0.3 rgb(120,130,230), stop:1 rgb(125,140,226));\
                border:1px;  \
                border-radius:5px; /*border-radius控制圆角大小*/\
                padding:2px 4px; \
            }\
            QPushButton:pressed{    \
                color: rgb(255, 255, 255); \
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(240,156,121), stop:0.3 rgb(220,160,140), stop:1 rgb(230,140,120));  \
                border:1px;  \
                border-radius:5px; /*border-radius控制圆角大小*/\
                padding:2px 4px; \
            }";
    ui->setupUi(this);
    this->setWindowTitle(" ");
    this->setFixedSize(238,120);

    QPoint globalPos = parent->mapToGlobal(QPoint(0, 0));
    int x = globalPos.x() + parent->width() - this->width();
    int y = globalPos.y();
    this->move(x, y);//窗口移动

    ui->pushButton->setStyleSheet(btnStyle2);
    ui->pushButton_2->setStyleSheet(btnStyle2);

}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_clicked()
{
    send(0);
}

void setting::on_pushButton_2_clicked()
{
    send(1);
}


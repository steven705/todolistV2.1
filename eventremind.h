#pragma execution_character_set("utf-8")

#ifndef EVENTREMIND_H
#define EVENTREMIND_H


#include <QDialog>
#include<QPaintEvent>
#include<QPixmap>
#include<qpainter.h>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QFont>
#include<QFileDialog>
#include <QByteArray>
#include "dbType.h"
#include <QComboBox>
#include<QDateTime>
#include<QLineEdit>
#include<QDateEdit>
#include<QTimeEdit>
#include <QMessageBox>
#include <QtMultimedia/QMediaPlayer>	
#include <QtMultimedia/QMediaPlaylist>
#include<QCloseEvent>



namespace Ui {
class eventRemind;
}

class eventRemind : public QDialog
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *)
    {
        emit send();
    }

signals:
    void send();

public:
    explicit eventRemind(QWidget *parent = nullptr);
    ~eventRemind();


    void closeMusic()
    {
        music->stop();
    }
    void set (QString n,int t,int ty)
    {
        this->n=n;
        this->t=t;
        if (ty==3)
        {
            this->setStyleSheet("background-color :#CC3399;");
        }
        else if (ty == 2)
        {
            this->setStyleSheet("background-color :#336699;");
        }
        else
        {
            this->setStyleSheet("background-color :rgb(166,164,208);");
        }
        name->setText(this->n);
        time->setText(QString::fromLocal8Bit("还有") + QString::number(this->t) + QString::fromLocal8Bit("分钟开始"));


       
        music->play();



    }

private:
    QMediaPlaylist* playlist;
    QMediaPlayer* music;
    QString n;
    int t;
    QLabel* name;
    QLabel* time;
    Ui::eventRemind *ui;
};

#endif // EVENTREMIND_H

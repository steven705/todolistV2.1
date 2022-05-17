#include "eventremind.h"
#include "ui_eventremind.h"
#include<QFont>
#include<QApplication>
#include<QDesktopWidget>

eventRemind::eventRemind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventRemind)
{


    ui->setupUi(this);

    setWindowTitle("提醒");

    n="";
    t=0;

    QFont font("楷体",50,50);
    setWindowState(Qt::WindowMaximized);
    name=new QLabel(this);
    time=new QLabel(this);

	int w = QApplication::desktop()->width();
	int h = QApplication::desktop()->height();
    name->resize(w,h/4);
    name->move(0,(h/4));
    time->resize(w,h/4);
    time->move(0, (h / 4)*2-100);
    name->setAlignment(Qt::AlignCenter);
    time->setAlignment(Qt::AlignCenter);


    name->setFont(font);
    time->setFont(font);

    name->setText(n);
    time->setText("还有"+QString::number(t)+"分钟就开始了");


    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/Dewdrops.wav"));
	playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music = new QMediaPlayer(this);
	music->setPlaylist(playlist);
}

eventRemind::~eventRemind()
{
    delete ui;
}

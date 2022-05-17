#include "focus.h"
#include "ui_focus.h"
#include <QDesktopWidget>

focus::focus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::focus)
{
    ui->setupUi(this);
	//setFixedSize(this->width(), this->height());
    setWindowState(Qt::WindowMaximized);
    this->setWindowTitle("FOCUS");

    myTimer = new QTimer(this);
    myTimer->start(1000);
    labelTime = new QLabel(this);
    ET = new QLabel(this);
    btToEt = new QLabel(this);
   

   
   

   
	int w=QApplication::desktop()->width();
	int h=QApplication::desktop()->height();

    labelTime->resize(w, (h/4)*2);
    ET->resize(w, (h / 4) );
    btToEt->resize(w, (h / 4));

    labelTime->move(0, 0);
    ET->move(0, (h / 4) *2-200 );
    btToEt->move(0, (h / 4) * 3-300);

	ET->setAlignment(Qt::AlignCenter);
	btToEt->setAlignment(Qt::AlignCenter);
	labelTime->setAlignment(Qt::AlignCenter);

    QFont font("Times New Roman", 100, 180);
    QFont font1("¿¬Ìå", 50, 50);
	labelTime->setFont(font);
	ET->setFont(font1);
	btToEt->setFont(font1);
	QDateTime curDateTime = QDateTime::currentDateTime();

	QString str = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
	QStringList list = str.split(" ");
	labelTime->setText(list[1]);


    connect(myTimer, &QTimer::timeout, [=]() {
		QDateTime curDateTime = QDateTime::currentDateTime();
		
		QString str=curDateTime.toString("yyyy-MM-dd hh:mm:ss");
        QStringList list = str.split(" ");
        labelTime->setText(list[1]);
        });
}

focus::~focus()
{
    myTimer->stop();
    delete ui;
}

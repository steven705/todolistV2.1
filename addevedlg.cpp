#include "addevedlg.h"
#include "ui_addevedlg.h"

addEVeDlg::addEVeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEVeDlg)
{
    ui->setupUi(this);
    this->setWindowTitle("Event");

	titel=new QLabel(this);
	name=new QLabel(this);
	dt=new QLabel(this);
	t=new QLabel(this);
	shixiangleixing=new QLabel(this);
	namer=new QLineEdit(this);
	evevtType=new QComboBox(this);
	bdt=new QDateEdit(this);
	edt=new QDateEdit(this);
	bt=new QTimeEdit(this);
	et=new QTimeEdit(this);
	beizhu1 = new QLabel(this);
	beizhu1->setText("备注:");
	beizhur = new QLineEdit(this);

	queding = new QPushButton(this);
	shanchu = new QPushButton(this);


	titel->setText("事项清单");
	name->setText("事项名称:");
	dt->setText("起止日期:");
	t->setText("起止时间:");
	shixiangleixing->setText("事项类型");

	evevtType->addItem("high");
	evevtType->addItem("middle");
	evevtType->addItem("low");


	bdt->setDisplayFormat("yyyy-MM-dd");
	edt->setDisplayFormat("yyyy-MM-dd");
	bt->setDisplayFormat("hh:mm:ss");
	et->setDisplayFormat("hh:mm:ss");


	connect(queding, &QPushButton::clicked, this,&addEVeDlg::on_ok_clicked);
	connect(shanchu, &QPushButton::clicked, this, &addEVeDlg::on_back_clicked);



	///开始设置布局
	this->setFixedSize(760, 680);


	QFont font("华文行楷", 17, 15);

    QFont font1("华文行楷", 24, 30);

	QFont font2("Times New Roman", 16, 15);

	titel->resize(250,100);
	titel->setAlignment(Qt::AlignCenter);

	titel->move(250, 50);
    titel->setFont(font);

	name->resize(150, 50);
	name->setFont(font);
	namer->resize(430, 50);
	namer->setFont(font2);

	dt->resize(150, 50);
	dt->setFont(font);
	bdt->resize(200, 50);
	edt->resize(200, 50);
	bdt->setFont(font2);
	edt->setFont(font2);

	

	t->resize(150, 50);
	t->setFont(font);
	bt->resize(200, 50);
	et->resize(200, 50);
	bt->setFont(font2);
	et->setFont(font2);


	shixiangleixing->resize(150, 50);
	shixiangleixing->setFont(font);
	evevtType->resize(430, 50);
	evevtType->setFont(font2);

	beizhu1->resize(150, 50);
	beizhu1->setFont(font);
	beizhur->resize(430, 50);
	beizhur->setFont(font2);

	

	name->move(70, 180);
	namer->move(250, 180);
	dt->move(70, 260);
	bdt->move(250, 260);
	edt->move(480, 260);

	t->move(70, 340);
	bt->move(250, 340);
	et->move(480, 340);

    shixiangleixing->move(70, 420);
	evevtType->move(250, 420);

	beizhu1->move(70, 500);
	beizhur->move(250, 500);

	queding->setText("确认");
	shanchu->setText("返回");

	queding->resize(200, 50);
	shanchu->resize(200, 50);

	queding->move(150, 580);
	shanchu->move(400, 580);


	QString btnStyle2 =
		"QPushButton{\
                color: rgb(255, 255, 255);\
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\
                border:1px;\
                border-radius:5px; /*border-radius控制圆角大小*/\
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

	queding->setStyleSheet(btnStyle2);
	shanchu->setStyleSheet(btnStyle2);
	queding->setFont(font);
	shanchu->setFont(font);


	bdt->setDate(QDate::currentDate());
	edt->setDate(QDate::currentDate());

	bt->setTime(QTime::currentTime());
	et->setTime(QTime::currentTime());


	


}
void addEVeDlg::set(todolist_ui_inf info)
{
	evevtType->setStyleSheet("border: 1px solid #A0A0A0; border-radius: 3px;padding-left: 5px; background-color: #F2F2F2;color: #A0A0A0;font - size: 10pt;");
	et->setStyleSheet("border: 1px solid #A0A0A0; border-radius: 3px;padding-left: 5px; background-color: #F2F2F2;color: #A0A0A0;font - size: 10pt;");
	bt->setStyleSheet("border: 1px solid #A0A0A0; border-radius: 3px;padding-left: 5px; background-color: #F2F2F2;color: #A0A0A0;font - size: 10pt;");
	edt->setStyleSheet("border: 1px solid #A0A0A0; border-radius: 3px;padding-left: 5px; background-color: #F2F2F2;color: #A0A0A0;font - size: 10pt;");
	bdt->setStyleSheet("border: 1px solid #A0A0A0; border-radius: 3px;padding-left: 5px; background-color: #F2F2F2;color: #A0A0A0;font - size: 10pt;");
	namer->setStyleSheet("border: 1px solid #A0A0A0; border-radius: 3px;padding-left: 5px; background-color: #F2F2F2;color: #A0A0A0;font - size: 10pt;");
	beizhur->setStyleSheet("border: 1px solid #A0A0A0; border-radius: 3px;padding-left: 5px; background-color: #F2F2F2;color: #A0A0A0;font - size: 10pt;");

	if (this->id==-1)
	{
		shanchu->setText("返回");
	}
	else
	{
		shanchu->setText("删除");
	}

	//将信息设置到上面
    namer->setText(info.EventTitle);
	QStringList l = info.BeginDT.split("-");
	QDate date1(l[0].toInt(), l[1].toInt(), l[2].toInt());
    bdt->setDate(date1);
	QStringList l2 = info.EndDT.split("-");
	QDate date2(l2[0].toInt(), l2[1].toInt(), l2[2].toInt());
	edt->setDate(date1);
	QStringList l3 = info.BeginT.split(":");
	QTime time3(l3[0].toInt(), l3[1].toInt(), l3[2].toInt());
	bt->setTime(time3);
	QStringList l4 = info.BeginT.split(":");
	QTime time4(l4[0].toInt(), l4[1].toInt(), l4[2].toInt());
	et->setTime(time4);

	if (info.EventType==3)
	{
		evevtType->setCurrentIndex(0);
	}
	else if (info.EventType == 2)
	{
		evevtType->setCurrentIndex(1);
	}
	else
	{
		evevtType->setCurrentIndex(2);
	}

	beizhur->setText(info.Note);

	
}

addEVeDlg::~addEVeDlg()
{
    delete ui;
}


void addEVeDlg::on_ok_clicked()
{
	todolist_ui_inf tmp;
	QString sname = namer->text();
	if (sname=="")
	{
		QMessageBox::information(this, "提示", "信息不完整");
		return;
	}
	tmp.EventTitle = sname;
	QStringList l = bdt->text().split("-");
	QDate date1(l[0].toInt(), l[1].toInt(), l[2].toInt());
	QStringList l2 = edt->text().split("-");
	QDate date2(l2[0].toInt(), l2[1].toInt(), l2[2].toInt());

	
	QStringList l3 = bt->text().split(":");
	QTime time3(l3[0].toInt(), l3[1].toInt(), l3[2].toInt());
	
	QStringList l4 =et->text().split(":");
	QTime time4(l4[0].toInt(), l4[1].toInt(), l4[2].toInt());

	if (date1>date2||time3>time4)
	{
		QMessageBox::information(this, "提示", "日期输入有误");
		return;
	}

	tmp.BeginDT = bdt->text();
	tmp.EndDT = edt->text();
	tmp.BeginT = bt->text();
	tmp.EndT = et->text();

	if (evevtType->currentIndex()==0)
	{
		tmp.EventType = 3;
	}
	else if (evevtType->currentIndex() == 1)
	{
		tmp.EventType = 2;
	}
	else
	{
		tmp.EventType = 1;
	}

	tmp.Note = beizhur->text();

	if (QMessageBox::Yes == QMessageBox::question(this, "提示", "您确定保存吗？", QMessageBox::Yes | QMessageBox::No))
	{
		//向主窗口发送
		emit sendInfToMain(tmp);
	}
}
void addEVeDlg::on_back_clicked()
{
	if (shanchu->text()=="删除")
	{
		emit sendDel();
	}
	else
	{
		this->close();
	}
}

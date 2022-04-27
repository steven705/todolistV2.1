#include "logon.h"
#include "ui_logon.h"

logon::logon(QWidget *parent) :QDialog(parent),
    ui(new Ui::logon)
{
    ui->setupUi(this);
    init();
}
void logon::init()
{
	nowSt = 0;
    this->setWindowTitle("Logon");
	this->setFixedSize(600, 940);

	name = new QLabel(this);
	nameShow = new QLineEdit(this);
	password = new QLabel(this);
	passwordShow = new QLineEdit(this);
	petname = new QLabel(this);
	petnameShow = new QLineEdit(this);
	birthday = new QLabel(this);
	birthdayShow = new QDateEdit(this);
	sex = new QLabel(this);
	sexShow = new QComboBox(this);
	sexShow->addItem("男");
	sexShow->addItem("女");
	note = new QLabel(this);
	noteShow = new QLineEdit(this);
	myBtn = new QPushButton(this);


	QFont font("华文行楷", 17, 15);
	name->setText("用户名");
	name->move(100, 450);
	name->setFont(font);
	name->resize(100, 50);

	password->setText("密码");

    //lineEdit->setPlaceholderText("范围为0-220,2位小数")
	password->move(100, 520);
	password->setFont(font);
	password->resize(100, 50);

	petname->setText("姓名");
	petname->move(100, 590);
	petname->setFont(font);
	petname->resize(100, 50);

	birthday->setText("生日");
	birthday->move(100, 660);
	birthday->setFont(font);
	birthday->resize(100, 50);

	sex->setText("性别");
	sex->move(100, 730);
	sex->setFont(font);
	sex->resize(100, 50);

	note->setText("个性签");
	note->move(100, 800);

	note->setFont(font);
	note->resize(100, 50);


    QFont font2("Times New Roman", 16, 15);
	nameShow->move(250, 450);
    nameShow->setFont(font2);
	nameShow->resize(300, 40);

	passwordShow->move(250, 520);
    QFont font3("Times New Roman", 10, 15);
    passwordShow->setPlaceholderText("7位以上的数字与字母组合");
    passwordShow->setFont(font3);
	passwordShow->resize(300, 40);

	petnameShow->move(250, 590);
    petnameShow->setFont(font2);
	petnameShow->resize(300, 40);

	birthdayShow->move(250, 660);
    birthdayShow->setFont(font2);
	birthdayShow->resize(300, 40);
	birthdayShow->setDisplayFormat("yyyy-MM-dd");


	sexShow->move(250, 730);
    sexShow->setFont(font2);
	sexShow->resize(300, 40);

	noteShow->move(250, 800);
    noteShow->setFont(font2);
	noteShow->resize(300, 40);



	QString btnStyle1 =
		"QPushButton{\
                color: rgb(255, 255, 255);\
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\
                border:1px;\
                border-radius:5px; /*border-radius控制圆角大小*/\
                padding:2px 4px;  \
            }\
            QPushButton:pressed{    \
                color: rgb(255, 255, 255); \
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(240,156,121), stop:0.3 rgb(220,160,140), stop:1 rgb(230,140,120));  \
                border:1px;  \
                border-radius:5px; /*border-radius控制圆角大小*/\
                padding:2px 4px; \
            }";
	tryLogon = new QPushButton(this);
	quitLogon = new QPushButton(this);
	tryLogon->setText("确认");
	quitLogon->setText("退出");
	tryLogon->move(250, 870);
	quitLogon->move(450, 870);
	tryLogon->resize(150, 50);
	quitLogon->resize(150, 50);
	tryLogon->setStyleSheet(btnStyle1);
	quitLogon->setStyleSheet(btnStyle1);

	connect(tryLogon, &QPushButton::clicked, this, &logon::logonToDb);
	connect(quitLogon, &QPushButton::clicked, [=]() {
		this->close();
		});

	//换头像

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

    myBtn->setText("挑选头像");
	myBtn->resize(100, 55);
	myBtn->move(440, 300);
	myBtn->setStyleSheet(btnStyle2);
	//QFont font("楷体", 10, 15);
	//myBtn->setFont(font);

	connect(myBtn, &QPushButton::clicked, [=]() {
		QString file_name = QFileDialog::getOpenFileName(this,
			QString("open Iamge"),
			".",
			QString("image files(*.jpg *.png *.bmp *.jfif)"));
		if (file_name != "")
		{
			pixPath = file_name;
			this->update();
			pict.load(pixPath);
			stDraw = true;
		}
		});
	pixPath = "";
}
void logon::paintEvent(QPaintEvent* event)
{
    if (stDraw ==true)
    {
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing, true);

		QPainterPath path;
		path.addEllipse(QPoint(300, 200), 150, 150);
		painter.setClipPath(path);

		painter.drawPixmap(QRect(150, 50, 300, 300), pict);
    }

}
void logon::logonToDb()
{
    tabel_userInf toSend;
    toSend.userName = nameShow->text();
    if(toSend.userName=="")
    {
        nameShow->setPlaceholderText("不允许为空");
        return;
    }
    if(toSend.userName.size()>20)
    {
        nameShow->setPlaceholderText("用户名过长");
        return;
    }

    toSend.password = passwordShow->text();
    QByteArray ch =  passwordShow->text().toLatin1();
        char *s = ch.data();
        char *p = ch.data();
        while (*s && *s >= '0' && *s <= '9')
            {
                s++;//如果是数字，指针后移
            }

        while ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
            {
                p++;//如果是字母，指针后移
            }

        if(passwordShow->text() == "")
            {
                passwordShow->setPlaceholderText("不允许为空");
                return;
            }
        //密码长度小于8
        else if (passwordShow->text().count() < 8)
        {
            passwordShow->setPlaceholderText("长度小于8位");
            return;
        }
        else if (*s == NULL)
        {//纯数字
             passwordShow->setPlaceholderText("不可以为纯数字");
             return;
        }
        else if (*p == NULL)
        {//纯字母
            passwordShow->setPlaceholderText("不可以为纯字母");
            return;
        }


    toSend.userPetName = petnameShow->text();
    toSend.birthday = birthdayShow->text();
    toSend.sex = sexShow->currentText();
    QStringList list = pixPath.split('.');
    toSend.suffix = list[list.size() - 1];
    toSend.pixmap = pict;
    toSend.path = pixPath;
    toSend.note = noteShow->text();
    if (nowSt==0)
    {
        emit sendlogonInf(toSend);
    }
    else
    {
        emit changedInf(toSend);
    }


}
logon::~logon()
{
    delete ui;
}

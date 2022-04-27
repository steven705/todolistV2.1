#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
   
    init();




    //获取当前日期进行显示
    QDateTime dt;
    QDate date;
    dt.setDate(date.currentDate());
    QString currentDate = dt.toString("yyyy-MM-dd");
	QString str = QString("%1日事项").arg(currentDate);
	myTitle->setText(str);

    NowUser.userName = "";

    //初始化
    nowEvent = myDb->searchNowDayData(NowUser.userName, currentDate);
    //显示到界面上

    myTodoWidget->SetBtnText(nowEvent);

    stlogOrshow = 1;

	//点击登录
	connect(mybtn, &QPushButton::clicked, [=]() {
		if (stlogOrshow == 1)
		{
			userLogin();
		}
		else
		{
			userShowInf();
		}

		});

    //接收日期
    connect(myCalwidget, &Window::sendDayToMain, [&](QString str) {
        //数据库查询
		QString s = QString("%1日事项").arg(str);
		myTitle->setText(s);
        

        nowEvent= myDb->searchNowDayData(NowUser.userName, str);
        myTodoWidget->SetBtnText(nowEvent);

        //用户选择日期
        

        });


    //监视来自todolist窗口的信号
    connect(myTodoWidget, &thingsWidget::send, [=](int id) {

        addEVeDlg *myShowEventDlg = new addEVeDlg(this);
        myShowEventDlg->setID(id);
        myShowEventDlg->show();
        if (id == -1)
        {
            //添加信息
        }
        else
        {
            myShowEventDlg->set(nowEvent[id]);
        }
        myShowEventDlg->show();
        //监控来自其信号 修改或者添加
        connect(myShowEventDlg, &addEVeDlg::sendInfToMain, [=](todolist_ui_inf tmp_info) {
            tmp_info.userName = NowUser.userName;
            bool st;
            if (id == -1)
            {
                //为其赋值添加时间
                 st = myDb->addNewData(tmp_info);
                 if (st==false)
                 {
                     QMessageBox::information(this, "提示", "插入失败");
                 }
                 else
                 {
                     //QMessageBox::information(this, "提示", "成功");
					 myShowEventDlg->close();
                 }
            }
            //修改
            else
            {
				tmp_info.addDate = nowEvent[id].addDate;
				tmp_info.addTime = nowEvent[id].addTime;
                st = myDb->alterData(tmp_info);
				if (st == false)
				{
					QMessageBox::information(this, "提示", "修改失败");
				}
				else
				{
					//QMessageBox::information(this, "提示", "成功");
					myShowEventDlg->close();
				}
            }
            if (st)
            {
				QDateTime dateTime(QDateTime::currentDateTime());
				QString qStr = dateTime.toString("yyyy-MM-dd hh:mm:ss");

				QStringList list = qStr.split(" ");
				QString str = QString("%1日事项").arg(list[0]);
				myTitle->setText(str);


				nowEvent = myDb->searchNowDayData(NowUser.userName, list[0]);
				myTodoWidget->SetBtnText(nowEvent);
            }

            });


        //发送删除消息
        connect(myShowEventDlg, &addEVeDlg::sendDel, [=]() {
            if (id!=1)
            {
               bool st= myDb->deleteData(nowEvent[id]);
               if (st)
               {
                   //QMessageBox::information(this, "提示", "删除成功");
				   QDateTime dateTime(QDateTime::currentDateTime());
				   QString qStr = dateTime.toString("yyyy-MM-dd hh:mm:ss");

				   QStringList list = qStr.split(" ");
				 
				   QString str = QString("%1日事项").arg(list[0]);
				   myTitle->setText(str);


				   nowEvent = myDb->searchNowDayData(NowUser.userName, list[0]);
				   myTodoWidget->SetBtnText(nowEvent);
                   myShowEventDlg->close();
               }
            }

            });

       
        });

    //监视来自 显示日程信息的窗口
    //修改或者添加

    //尝试一下登录之前的用户

	bool file = trylast();
	if (file)
	{
		bool isOk = myDb->login(NowUser);
		if (isOk)
		{
			stlogOrshow = 0;


			QDateTime dateTime(QDateTime::currentDateTime());
			QString qStr = dateTime.toString("yyyy-MM-dd hh:mm:ss");

			QStringList list = qStr.split(" ");
			QString str = QString("%1日事项").arg(list[0]);
			myTitle->setText(str);


			nowEvent = myDb->searchNowDayData(NowUser.userName, list[0]);
			myTodoWidget->SetBtnText(nowEvent);
			mybtn->setText("用户");
		}
	}


	
    

}

bool Widget::trylast()
{
	QFile file("myFile.dat");
	if (!file.open(QIODevice::ReadOnly))
	{
		return false;
	}
	QDataStream ds(&file);
	ds >> NowUser.userName;
	ds >> NowUser.password;
	ds >> NowUser.userPetName;
	ds >> NowUser.birthday;
	ds >> NowUser.sex;
	ds >> NowUser.byteArray;
	ds >> NowUser.path;
	ds >> NowUser.suffix;
	ds >> NowUser.pixmap;

	file.close();
	return true;
}

//将str转换为Qdate

void Widget::init()
{
   

    this->setWindowIcon(QIcon(":/icon.png"));
    this->setFixedSize(1300, 900);
    this->setWindowTitle("Todolist");

    myCalwidget = new Window(this);
    myTodoWidget = new thingsWidget(this);

    myCalwidget->resize(700, 900);
    myTodoWidget->move(700, 60);

    mybtn = new QPushButton(this);
    mybtn->move(1200, 0);
    mybtn->resize(100, 60);
	QFont font0("楷体", 12, 20);
	mybtn->setFont(font0);
    mybtn->setText("登录");

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
    mybtn->setStyleSheet(btnStyle2);



	QString btnStyle =
		"QPushButton{\
                color: rgb(255, 255, 255);\
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\
                border:1px;\
                padding:2px 4px;  \
            }\
         ";

    myTitle = new QPushButton(this);
    myTitle->move(700, 0);
    myTitle->resize(500, 60);
    QFont font("宋体", 18, 20);
    myTitle->setFont(font);
	myTitle->setStyleSheet(btnStyle);

	
    

      myDb=new mySqlConnect(this);
      if(myDb->connect())
      {
           QMessageBox::information(this, "infor", "success");
      }
      else
      {
             QMessageBox::information(this, "infor", "fail");
             //qDebug()<<"error open database because"<<db.lastError().text();
      }
     
     
}

//登录部分
void Widget::userLogin()
{
	login* mylogin = new login(this);

	if (logonName != "/o*&&-.+.*")
	{
		mylogin->set(logonName);
		logonName = "/o*&&-.+.*";
	}

	//注册新用户
	connect(mylogin, &login::sendlogon, [=]() {
		userLogon();
		mylogin->close();
		});

	connect(mylogin, &login::send, [=](QString name, QString password)
		{

			//看看能不能登录成功
			tabel_userInf myUser;
			myUser.userName = name;
			myUser.password = password;
			bool isOk = myDb->login(myUser);
			if (isOk)
			{

				mybtn->setText("用户");
				stlogOrshow = 0;
				NowUser = myUser;
				userShowInf();
				mylogin->close();

				QDateTime dateTime(QDateTime::currentDateTime());
				QString qStr = dateTime.toString("yyyy-MM-dd hh:mm:ss");

				QStringList list = qStr.split(" ");

				QString str = QString("%1日事项").arg(list[0]);
				myTitle->setText(str);
                


				nowEvent = myDb->searchNowDayData(NowUser.userName, list[0]);
				myTodoWidget->SetBtnText(nowEvent);
			}
			else
			{
				mylogin->errorPrompt();
			}

		});

	mylogin->show();

}

//展示部分
void Widget::userShowInf()
{
	ShowInf* showUserInf = new ShowInf(this);
	showUserInf->set(NowUser.userPetName, NowUser.birthday, NowUser.sex, NowUser.note, NowUser.suffix, NowUser.byteArray);
	showUserInf->show();
	//修改头像
	connect(showUserInf, &ShowInf::changedPic, [=](tabel_userInf tmpmyUser)
		{
			NowUser.path = tmpmyUser.path;
			NowUser.suffix = tmpmyUser.suffix;

			bool isOk = myDb->changeUserInf(NowUser, 0);



		});
	//修改用户
	connect(showUserInf, &ShowInf::goingChangeUser, [=]()
		{
			showUserInf->close();
			stlogOrshow = 1;
			mybtn->clicked(true);
		});
	//修改资料
	connect(showUserInf, &ShowInf::goingChangeInf, [=]()
		{
			logon* mylogon = new logon(this);
			mylogon->set(NowUser);
			mylogon->show();
			connect(mylogon, &logon::changedInf, [=](tabel_userInf tmpmyUser)
				{
					NowUser.password = tmpmyUser.password;
					NowUser.userPetName = tmpmyUser.userPetName;
					NowUser.birthday = tmpmyUser.birthday;
					NowUser.sex = NowUser.sex;
					NowUser.note = tmpmyUser.note;
					NowUser.password = tmpmyUser.password;
					bool isOk = myDb->changeUserInf(NowUser, 1);
					if (isOk)
					{
						mylogon->close();
						showUserInf->set(NowUser.userPetName, NowUser.birthday, NowUser.sex, NowUser.note, NowUser.suffix, NowUser.byteArray);
					}
					else
					{
						QMessageBox::information(this, "提示", "修改失败");
					}
				});
		});


}

//注册部分
void Widget::userLogon()
{
	logon* mylogon = new logon(this);
	mylogon->show();
	connect(mylogon, &logon::sendlogonInf, [=](tabel_userInf userInfToLogon)
		{
			bool st = myDb->logon(userInfToLogon);
			if (st)
			{
				logonName = userInfToLogon.userName;
				stlogOrshow = 1;
				QMessageBox::information(this, "提示", "注册成功");
				mylogon->close();
				mybtn->clicked(true);
			}
			else
			{
				QMessageBox::information(this, "提示", "账户重命名");
			}
		});

}


Widget::~Widget()
{
    myDb->closeConnect();

	QFile file("myFile.dat");
	if (!file.open(QIODevice::WriteOnly))
	{
		return;
	}
	QDataStream ds(&file);
    ds << NowUser.userName;
    ds << NowUser.password;
    ds << NowUser.userPetName;
    ds << NowUser.birthday;
    ds << NowUser.sex;
    ds << NowUser.byteArray;
    ds << NowUser.path;
    ds << NowUser.suffix;
    ds << NowUser.pixmap;
	
    file.close();

    delete ui;
}


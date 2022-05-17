#include "mysqlconnect.h"
#include <QMessageBox>

mySqlConnect::mySqlConnect(QObject *parent) : QObject(parent)
{

}
//连接数据库
bool mySqlConnect::connect()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("47.98.181.12");
    db.setPort(3306);
    db.setDatabaseName("todolist");
    db.setUserName("user_todolist");
    db.setPassword("15377619612Lzx@");
    if (db.open())
    {
        query=QSqlQuery(db);
        return true;
    }
    else
    {
        return false;
    }
}
 //用户验证
bool mySqlConnect::login(tabel_userInf& myUser)
{
	QString str = QString("select * from userInf where userName='%1' and userPassword= '%2'")
		.arg(myUser.userName).arg(myUser.password);
	query.exec(str);
	//只要有结果就查询成功了
	//同时将信息复制过来
	while (query.next())
	{
		//将信息复制过来
		myUser.userPetName= query.value(2).toString();
		myUser.birthday = query.value(3).toString();
		myUser.sex = query.value(4).toString();
		myUser.note = query.value(5).toString();
		myUser.suffix= query.value(6).toString();
		myUser.byteArray = query.value(7).toByteArray();
		return true;
	}
	return false;
}
//用户注册
bool mySqlConnect::logon(tabel_userInf myUser)
{
    //先看一下这个用户名是不是存在的
	//存在的话
	QString str = QString("select * from userInf where userName='%1'").arg(myUser.userName);
	query.exec(str);
	//只要有结果说明用户名被用了
	while (query.next())
	{
        return false;
	}

	//将照片以二进制流的方式存到数据库
	QByteArray data;
	QString path =myUser.path;
	QFile* file = new QFile(path); //fileName为二进制数据文件名  
	file->open(QIODevice::ReadOnly);
	data = file->readAll();
	file->close();
	QVariant var(data);
	

	QString strQSL = QString("insert into  userInf values('%1','%2','%3','%4','%5','%6','%7',?)")
        .arg(myUser.userName).arg(myUser.password).arg(myUser.userPetName).
		arg(myUser.birthday).arg(myUser.sex).arg(myUser.note).arg(myUser.suffix);
	query.prepare(strQSL);
	query.addBindValue(var);
	return query.exec();
}
//修改用户信息
bool mySqlConnect::changeUserInf(tabel_userInf& myUser, int i)
{
	bool st6 = true, st7 = true;
	//表示修改头像
	if (i == 0)
	{
		//将照片以二进制流的方式存到数据库
		QByteArray data;
		QString path = myUser.path;
		QFile* file = new QFile(path); //fileName为二进制数据文件名  
		file->open(QIODevice::ReadOnly);
		data = file->readAll();
		myUser.byteArray.clear();
		myUser.byteArray.squeeze();
		int t = data.size();
		myUser.byteArray.resize(t + 1000);
		myUser.byteArray = data;
		file->close();
		QVariant var(data);
		QString strQSL = QString("update userInf set userPicture= ? where userName='%1'").arg(myUser.userName);
		query.prepare(strQSL);
		query.addBindValue(var);
		st7 = query.exec();


		QString strQSL6 = QString("update userInf set suffix='%2' where userName='%1'").arg(myUser.userName).arg(myUser.suffix);
		st6 = query.exec(strQSL6);
	}





	//分别修改 这里是一个bug
	QString strQSL2 = QString("update userInf set userPetName='%2' where userName='%1'").arg(myUser.userName).arg(myUser.userPetName);
	bool st2 = query.exec(strQSL2);
	QString strQSL3 = QString("update userInf set userBirthday='%2' where userName='%1'").arg(myUser.userName).arg(myUser.birthday);
	bool st3 = query.exec(strQSL3);
	QString strQSL4 = QString("update userInf set userSex='%2' where userName='%1'").arg(myUser.userName).arg(myUser.sex);
	bool st4 = query.exec(strQSL4);
	QString strQSL5 = QString("update userInf set userNote='%2' where userName='%1'").arg(myUser.userName).arg(myUser.note);
	bool st5 = query.exec(strQSL5);



	return st2 && st3 && st4 && st5 && st6 && st7;

}

//添加新数据
bool mySqlConnect::addNewData(todolist_ui_inf myuiInf)
{
	QDateTime dateTime(QDateTime::currentDateTime());
	QString qStr = dateTime.toString("yyyy-MM-dd hh:mm:ss");

	QStringList list = qStr.split(" ");

	//添加的日期和时间
    QString strQSL = QString("insert into infTodo2 values('%1','%2','%3','%4','%5','%6','%7','%8',%9,'%10',%11)")
		.arg(myuiInf.userName).arg(list[0]).arg(list[1]).arg(myuiInf.BeginDT).arg(myuiInf.EndDT).
		arg(myuiInf.BeginT).arg(myuiInf.EndT).
		arg(myuiInf.EventTitle).arg(myuiInf.EventType).arg(myuiInf.Note).arg(myuiInf.timeR);
	return query.exec(strQSL);
}


//删除信息
bool mySqlConnect::deleteData(const todolist_ui_inf& myuiInf)
{
	//将信息 删除
	QString strQSL = QString("delete from infTodo2 where userName='%1' and addDate='%2' and addTime='%3'")
	       .arg(myuiInf.userName).arg(myuiInf.addDate).arg(myuiInf.addTime);
	return query.exec(strQSL);
}
//4
//根据传入的信息将数据从数据库修改  infToDoList 
//todolist_ui_inf& myuiInf 是ui界面传入的(显示详细信息的部分)
bool mySqlConnect::alterData(todolist_ui_inf& myuiInf)
{
	QString strQSL = QString("update infTodo2 set BeginDT ='%1',EndDT='%2',BeginT ='%3',EndT='%4',EventTitle='%5',EventType=%6,Note='%7',remind=%8 where userName='%9' and addDate='%10' and addTime='%11'")
		.arg(myuiInf.BeginDT).arg(myuiInf.EndDT).
		arg(myuiInf.BeginT).arg(myuiInf.EndT).
		arg(myuiInf.EventTitle).arg(myuiInf.EventType).arg(myuiInf.Note)
		.arg(myuiInf.timeR).arg(myuiInf.userName).arg(myuiInf.addDate).arg(myuiInf.addTime);
	bool st= query.exec(strQSL);
	return st;
}

//查询当日事项的所有信息返回
QVector<todolist_ui_inf> mySqlConnect::searchNowDayData(QString nowUser,QString Nowday)
{
	QString str = QString("select * from infTodo2 where userName='%1' and '%2'>= BeginDT and '%2'<= EndDT").arg(nowUser).arg(Nowday);
	query.exec(str);
	
	QVector<todolist_ui_inf> ret;
	while (query.next())
	{
		todolist_ui_inf tmp;
		tmp.userName = query.value(0).toString();
		tmp.addDate = query.value(1).toString();
		tmp.addTime = query.value(2).toString();
		tmp.addTime = tmp.addTime.mid(0, 8);
		tmp.BeginDT = query.value(3).toString();
		tmp.EndDT = query.value(4).toString();
		tmp.BeginT = query.value(5).toString();
		tmp.BeginT = tmp.BeginT.mid(0, 8);
		tmp.EndT = query.value(6).toString();
		tmp.EndT = tmp.EndT.mid(0, 8);
		tmp.EventTitle = query.value(7).toString();
		tmp.EventType = query.value(8).toInt();
		tmp.Note = query.value(9).toString();
		tmp.timeR = query.value(10).toInt();
		ret.push_back(tmp);
	}
	return ret;
}


//根据事项姓名查询
QVector<todolist_ui_inf> mySqlConnect::searchDataByName(QString nowUser, QString eventName)
{
	QVector<todolist_ui_inf> ret;
	QString str = QString("select * from infTodo2 where EventTitle like '\%%1\%' and userName='%2'").arg(eventName).arg(nowUser);
	query.exec(str);
	while (query.next())
	{
		todolist_ui_inf tmp;
		tmp.userName = query.value(0).toString();
		tmp.addDate = query.value(1).toString();
		tmp.addTime = query.value(2).toString();
		tmp.addTime = tmp.addTime.mid(0, 8);
		tmp.BeginDT = query.value(3).toString();
		tmp.EndDT = query.value(4).toString();
		tmp.BeginT = query.value(5).toString();
		tmp.BeginT = tmp.BeginT.mid(0, 8);
		tmp.EndT = query.value(6).toString();
		tmp.EndT = tmp.EndT.mid(0, 8);
		tmp.EventTitle = query.value(7).toString();
		tmp.EventType = query.value(8).toInt();
		tmp.Note = query.value(9).toString();
		tmp.timeR = query.value(10).toInt();
		ret.push_back(tmp);
	}

	return ret;
}


//关闭数据库连接
void mySqlConnect::closeConnect()
{
    db.close();
}

bool mySqlConnect::check(QString title,int time,int type,QString userName, todolist_ui_inf& myret)
{

	QDateTime dateTime(QDateTime::currentDateTime());
	QString qStr = dateTime.toString("yyyy-MM-dd hh:mm:ss");

	QStringList list = qStr.split(" ");

   

    QString str = QString("select * from infTodo2 where '%1'>= BeginDT and '%1'<= EndDT and userName='%2'and remind<>-1").arg(list[0]).arg(userName);
    query.exec(str);
	QVector<todolist_ui_inf> ret;

    while (query.next())
    {
        todolist_ui_inf tmp;
        tmp.userName = query.value(0).toString();
        tmp.addDate = query.value(1).toString();
        tmp.addTime = query.value(2).toString();
        tmp.addTime = tmp.addTime.mid(0, 8);
        tmp.BeginDT = query.value(3).toString();
        tmp.EndDT = query.value(4).toString();
        tmp.BeginT = query.value(5).toString();
        tmp.BeginT = tmp.BeginT.mid(0, 8);
        tmp.EndT = query.value(6).toString();
        tmp.EndT = tmp.EndT.mid(0, 8);
        tmp.EventTitle = query.value(7).toString();
        tmp.EventType = query.value(8).toInt();
        tmp.Note = query.value(9).toString();
		tmp.timeR = query.value(10).toInt();
		ret.push_back(tmp);

    }
	bool st = false;
	//开始遍历时间
	for (int i=0;i<ret.size();i++)
	{
		QStringList list1 = list[1].split(":");
		QTime t1(list1[0].toInt(), list1[1].toInt(), list1[2].toInt());
		QStringList list2 = ret[i].BeginT.split(":");
		QTime t2(list2[0].toInt(), list2[1].toInt(), list2[2].toInt());

		if ((ret[i].timeR * 60)-1<=t1.secsTo(t2)&& t1.secsTo(t2) <= (ret[i].timeR * 60)+1)
		{
			myret.userName = ret[i].userName;
			myret.addDate = ret[i].addDate;
			myret.addTime = ret[i].addTime;
			myret.BeginDT = ret[i].BeginDT;
			myret.EndDT = ret[i].EndDT;
			myret.BeginT = ret[i].BeginT;
			myret.EndT = ret[i].EndT;
			myret.EventTitle = ret[i].EventTitle;
			myret.EventType = ret[i].EventType;
			myret.Note = ret[i].Note;
			myret.timeR = ret[i].timeR;
			st = true;
			break;
		}
	}


	return st;


}


QString mySqlConnect::getQuotes()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QString sel = QString("select count(*) from Quotes");
    query.exec(sel);
    int num;
    while (query.next())
    {
        num = query.value(0).toInt();
    }
     QString ret;
    while (true)
    {
        int id = qrand()%num;
        QString sel2 = QString("select saying from Quotes where id=%1").arg(id);
        query.exec(sel2);
        while (query.next())
        {
            ret = query.value(0).toString();
        }
        if(ret.size()<=40)break;
    }
    return ret;
}


//获取近三周的信息
void mySqlConnect::getWeekNum(QVector<DT_EVENUM> &f,QVector<DT_EVENUM> &s,QVector<DT_EVENUM> &t,QString nowUser,QDateTime nowday)
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_week = current_date_time.toString("ddd");
    QDateTime start;
    QDateTime end;
    current_date_time=nowday;
    if(current_week=="周一")
    {
        start=current_date_time.addDays(-7);
        end=current_date_time.addDays(13);
    }
    else if(current_week=="周二")
    {
        start=current_date_time.addDays(-8);
        end=current_date_time.addDays(12);
    }
    else if(current_week=="周三")
    {
        start=current_date_time.addDays(-9);
        end=current_date_time.addDays(11);
    }
    else if(current_week=="周四")
    {
        start=current_date_time.addDays(-10);
        end=current_date_time.addDays(10);
    }
    else if(current_week=="周五")
    {
        start=current_date_time.addDays(-11);
        end=current_date_time.addDays(9);
    }
    else if(current_week=="周六")
    {
        start=current_date_time.addDays(-12);
        end=current_date_time.addDays(8);
    }
    else if(current_week=="周日")
    {
        start=current_date_time.addDays(-13);
        end=current_date_time.addDays(7);
    }
    int i=0;
    while (start<=end)
    {
		QString str0 = end.toString("yyyy-MM-dd hh:mm:ss");
        QString str = start.toString("yyyy-MM-dd hh:mm:ss");
        QStringList list=str.split(" ");
        QString strq = QString("select count(*) from infTodo2 where userName='%1' and '%2'>= BeginDT and '%2'<= EndDT").arg(nowUser).arg(list[0]);
        query.exec(strq);


        if(query.next())
        {
            int num = query.value(0).toInt();
            if(i<=6)
            {
                f[i].day= start;
                f[i].num=num;
            }
            else if(i>=7&&i<=13)
            {
                s[i-7].day= start;
                s[i-7].num=num;
            }
            else
            {
                t[i-14].day= start;
                t[i-14].num=num;
            }

        }
		start=start.addDays(1);
        i++;
    }

}

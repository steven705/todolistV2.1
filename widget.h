#pragma once
#pragma execution_character_set("utf-8")
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"tdlcalendar.h"
#include"mysqlconnect.h"
#include"dbType.h"
#include"login.h"
#include"logon.h"
#include"showinf.h"
#include"thingswidget.h"
#include<QDate>
#include<qlabel.h>
#include<qfont.h>
#include "addevedlg.h"
#include <QDataStream>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //登录部分
    void userLogin();

    //展示部分
    void userShowInf();

    //注册部分
    void userLogon();

    //初始化函数
    void init();

    bool trylast();


private:
    Ui::Widget *ui;

   

    //日历界面
    Window * myCalwidget;

    //显示界面
    thingsWidget* myTodoWidget;

    //今天的查询结果
    QVector<todolist_ui_inf> nowEvent;

    bool trylogin;


    mySqlConnect* myDb;
   

    //用来登录的按钮
    QPushButton* mybtn;

    //0表示未登录 1表示登录了
    int nowCase;

    //当前的用户的信息
    tabel_userInf NowUser;

    //
    QPushButton* myTitle;
    

	//1表示登录
	int stlogOrshow;

    QString logonName = "/o*&&-.+.*";


   
};
#endif // WIDGET_H

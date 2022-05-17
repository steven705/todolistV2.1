#ifndef MYSQLCONNECT_H
#define MYSQLCONNECT_H

#include <QObject>
#include<QSqlQuery>
#include <QPixmap>
#include <QBuffer>
#include <QByteArray>
#include <QVariant>
#include <QVector>
#include "dbType.h" //这个存储的数据库的表
#include <QFile>
#include<qdatetime.h>
#include<QDebug>
#include <qmath.h>

class mySqlConnect : public QObject    
{
    Q_OBJECT
public:
    explicit mySqlConnect(QObject *parent = nullptr);
    //连接数据库
    bool connect();
    //登录
    bool login(tabel_userInf& myUser);
    //注册
    bool logon(tabel_userInf myUser);
    //修改用户信息
    bool changeUserInf(tabel_userInf& myUser, int i);
    //添加新的事项
    bool addNewData(todolist_ui_inf myuiInf);
    //查询当日事项
    QVector<todolist_ui_inf> searchNowDayData(QString nowUser,QString Nowday);
    QVector<todolist_ui_inf> searchDataByName(QString nowUser, QString eventName);
    //根据传入的信息将数据删除
    bool deleteData(const todolist_ui_inf& myuiInf);
    //根据传入的数据将信息进行修改
    bool alterData(todolist_ui_inf& myuiInf);
    //关闭数据库连接
    void closeConnect();

    //检查是否到提醒时间了
    bool check(QString title, int time, int type, QString userName, todolist_ui_inf& myre);

    QString getQuotes();

    void getWeekNum(QVector<DT_EVENUM> &f,QVector<DT_EVENUM> &s,
                    QVector<DT_EVENUM> &t,QString nowUser,QDateTime nowday);

private:
    //负责连接数据库
     QSqlDatabase db;
     //负责执行查询语句
     QSqlQuery query;

signals:


};

#endif // MYSQLCONNECT_H

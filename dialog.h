#pragma execution_character_set("utf-8")

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"dbType.h"
#include<qmessagebox.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

   

    //设置初始值 显示的信息
    void set(todolist_ui_inf info);

    void on_add_clicked();

    void on_back_clicked();

   

    //设置初始id
    void setID(int i)
    {
        this->id = i;
    }


private slots:
    //添加按钮事件  发送todolist_ui_inf
    //void on_add_clicked();
    //返回按钮事件
    //void on_back_clicked();
    //事件类型？
   //void on_range_clicked();

signals:
    //将消息传送回todolist界面 再转发到主界面
    void sendInfToMain(todolist_ui_inf);

signals:
    void sendDel();

private:
    Ui::Dialog *ui;

    int id;
};

#endif // DIALOG_H

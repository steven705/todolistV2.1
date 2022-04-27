#ifndef thingsWidget_H
#define thingsWidget_H

#include <QWidget>
#include <QGraphicsScene>
#include<QPushButton>
#include<QGraphicsLinearLayout>
#include <vector>
#include <QGraphicsWidget>
#include "dialog.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class thingsWidget; }
QT_END_NAMESPACE


class MyPushButton :public QPushButton {
    Q_OBJECT
private:
    int myID;
public:
    MyPushButton(QWidget* parent = nullptr)
        :QPushButton(parent) {}
    ~MyPushButton() {}
    // 设置按钮myID
    void setmyID(int id_number) {
        myID = id_number;
    }
    // 获取按钮myID
    int getmyID() {
        return myID;
    }
};


class thingsWidget : public QWidget
{
    Q_OBJECT

public:
    thingsWidget(QWidget *parent = nullptr);
    ~thingsWidget();
    void on_pushButton_clicked();



    void sendClickedToMain();

    void SetBtnText(const QVector<todolist_ui_inf>& SerchEvent);

signals:
    //id是点击哪一个按钮 mycase=0表示显示 1表示添加
    void send(int id);

private:
    Ui::thingsWidget *ui;
   
    QGraphicsScene* scene;
    QGraphicsLinearLayout* layout;
    vector<QPushButton*> vec_btn;
    QGraphicsWidget* form;
   
};
#endif // WIDGET_H

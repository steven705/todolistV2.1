#ifndef ADDEVEDLG_H
#define ADDEVEDLG_H

#include <QDialog>
#include<QPaintEvent>
#include<QPixmap>
#include<qpainter.h>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QFont>
#include<QFileDialog>
#include <QByteArray>
#include "dbType.h"
#include <QComboBox>
#include<QDateTime>
#include<QLineEdit>
#include<QDateEdit>
#include<QTimeEdit>
#include <QMessageBox>

namespace Ui {
class addEVeDlg;
}

class addEVeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit addEVeDlg(QWidget *parent = nullptr);
    ~addEVeDlg();

	//设置初始值 显示的信息
    void set(todolist_ui_inf info);




	//设置初始id
	void setID(int i)
	{
		this->id = i;
	}

signals:
	//将消息传送回todolist界面 再转发到主界面
	void sendInfToMain(todolist_ui_inf);

signals:
	void sendDel();


public slots:
    void on_ok_clicked();
public slots:
    void on_back_clicked();

private:
    Ui::addEVeDlg *ui;

    QLabel* titel;
    QLabel* name;
    QLabel* dt;
    QLabel* t;
    QLabel* shixiangleixing;
    QLabel* beizhu1;
    QLineEdit* namer;
    QComboBox* evevtType;
    QDateEdit* bdt;
    QDateEdit* edt;
    QTimeEdit* bt;
    QTimeEdit* et;
    QLineEdit* beizhur;

    QPushButton* queding;
    QPushButton* shanchu;

    int id;

};

#endif // ADDEVEDLG_H

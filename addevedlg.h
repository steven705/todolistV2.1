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

	//���ó�ʼֵ ��ʾ����Ϣ
    void set(todolist_ui_inf info);




	//���ó�ʼid
	void setID(int i)
	{
		this->id = i;


		bdt->setDate(QDate::currentDate());
		edt->setDate(QDate::currentDate());

        QDateTime curDateTime=QDateTime::currentDateTime();
        QString str=curDateTime.toString("yyyy-MM-dd hh:mm:ss");
        QStringList list=str.split(" ");
        QStringList list1=list[1].split(":");
        QTime t1(list1[0].toInt(),list1[1].toInt());
        QTime t2=t1.addSecs(7200);
        bt->setTime(t1);
        et->setTime(t2);
	}

signals:
	//����Ϣ���ͻ�todolist���� ��ת����������
	void sendInfToMain(todolist_ui_inf);

signals:
	void sendDel();


public slots:
    void on_ok_clicked();
public slots:
    void on_back_clicked();

private:

    int remindT;



    Ui::addEVeDlg *ui;

    QLabel* titel;
    QLabel* name;
    QLabel* dt;
    QLabel* t;
    QLabel* shixiangleixing;
    QLabel* beizhu1;
    QLabel* tixing;
    QLineEdit* namer;
    QComboBox* evevtType;
    QDateEdit* bdt;
    QDateEdit* edt;
    QTimeEdit* bt;
    QTimeEdit* et;
    QLineEdit* beizhur;
    QComboBox* tixingType;

    QPushButton* queding;
    QPushButton* shanchu;

    int id;

};

#endif // ADDEVEDLG_H

#ifndef TDLCALENDAR_H
#define TDLCALENDAR_H

#pragma once


#include <QtWidgets/QWidget>
#include "ui_TDLCalendar.h"
#include "CalendarWidget.h"
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qpainter.h>
#include <qdebug.h>
#include <qboxlayout.h>
#include <QFile>
//namespace Ui {
//    class TDLCalendar;
//}
class Window : public QWidget
{
    Q_OBJECT

private:
    QString nowDaystr="故人西辞黄鹤楼";
public:
    void setNowdayStr(QString str)
    {

        nowDaystr="";
        int size = 0;
        for (int i=0;i<str.size()-2;i++)
        {
            if (str[i]=='b'||str[i]=='f')
            {
                break;
            }
			if (size==14)
			{
				nowDaystr = nowDaystr + '\n';
                i--;
                size = 0;
			}
			else
			{
				nowDaystr = nowDaystr + str[i];
                size++;
			}
        }
        labelOneNoteEveryDay->setText(nowDaystr);
    }

public:
    Window(QWidget *parent = Q_NULLPTR);
    ~Window();
    void initWidget();
    void initStyle();
    void sltDayClicked(int nday);
    void sltDayChanged();
    void sltDateJump();
    void sltBack2today();
    void paintEvent(QPaintEvent*);
    
    CalendarWidget* calendar;

    QWidget* widgetRight;

    //QLabel* labelShowToday;
    //QLabel* labelShowWeek;
    QLabel* labelShowDay;
    QLabel* labelShowNYear;
    QLabel* labelShowLunarDate;
    //QLabel* labelSpacer;
    QLabel* labelScheduleTitle;
    QLabel* labelSchedule;
    //QLabel* labelShowYear;
    QLabel* labelOneNoteEveryDay;

    QHBoxLayout* verlayoutWidgetRight;
    QVBoxLayout* H1;
    QVBoxLayout* H2;
    QVBoxLayout* H3;
    //QLabel* Ly;
    //QLabel* Lj;
    //QLabel* ls2;
    QHBoxLayout* horLayoutGlobal;
    QVBoxLayout* horLayoutWidget;
    QGroupBox* groupBoxBottom;

    QLabel* labelYearJump;
    QLabel* labelMonthJump;
    QLabel* labelDayJump;

    QLineEdit* editDayJump;
    QLineEdit* editMonthJump;
    QLineEdit* editYearJump;

    QPushButton* btnDateJump;
    QPushButton* btnToday;

    QHBoxLayout* horLayoutJump;
    QVBoxLayout* verLayoutAll;

signals:
    void sendDayToMain(QString str);
private:
    //Ui::TDLCalendarClass ui;
};


#endif // TDLCALENDAR_H

#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H
#pragma execution_character_set("utf-8")
#include <qwidget.h>
#include <qlabel.h>
#include <qdate>
#include <qvboxlayout>
#include<qpushbutton.h>
#include<qvariant.h>
#include <qdebug.h>
#include "date.h"
typedef enum {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Week
} E_WEEK;
//
typedef enum {
    PREV_MONTH_DAY,     // 上月剩余天数
    NEXT_MONTH_DAY,     // 下个月的天数
    CURR_MONTH_DAY,     // 当月天数
    WEEKEND_DAY,        // 周末
    CURRENT_DAY,        // 当天
} E_DAY;
//
///// 自定义的日子显示控件
/////
class DayLabel : public QLabel {
    Q_OBJECT

public:
    explicit DayLabel(QWidget* parent = 0);

    bool bSelect;
    bool getBSelect() const;
    void setSelected(bool value);
    void setColor(const int& type);
    void showDay(int nDay, int nmonth, int nYear, QString strLunar);

    int m_nDay;
    int m_nMonth;
    int m_nYear;
signals:
    void signalClicked(int ntype, int day);
signals:
    //向cal转发
    void sendDayToCalendar(QString str);
private:
    QLabel* labelIcon;
public:
    void enterEvent(QEvent* e);
    void leaveEvent(QEvent* e);
    void mousePressEvent(QMouseEvent* e);
    //void mouseDoubleClickEvent(QMouseEvent* e);
};

class CalendarWidget :
    public QWidget
{
    Q_OBJECT
private:
    int m_nYear;
    int m_nMonth;
    int m_nDay;
public:
    CalendarWidget(QWidget* parent = Q_NULLPTR);
    int year() const;
    void setYear(int year);

    int month() const;
    void setMonth(int month);

    int day() const;
    void setDay(int day);
    void jumpTodate(int year, int month, int day);

    void initWidget();
    void initDate();
    void sltDayClicked(int type, int day);
signals:
    void signalDayClicked(int nday);
    void signalDayChanged();
    //void signalClicked(int ntype, int year, int month, int day);

signals:
    void sendDayToTDL(QString str);
private:

    QVBoxLayout* verLayoutCalendar;

    QWidget* widgetTitle;
    QLabel* labelTitle;
    QPushButton* btnPrevMonth;
    QPushButton* btnNextMonth;
    QHBoxLayout* horLayoutTitle;

    QWidget* widgetWeek;
    QLabel* labelWeek[Week];
    QHBoxLayout* horLayoutWeek;

    QWidget* widgetBody;
    DayLabel* labelDay[42];
    QGridLayout* gridLayoutBody;

    //QWidget* widgetRight;

    //QLabel* labelShowToday;
    //QLabel* labelShowWeek;
    //QLabel* labelShowDay;
    //QLabel* labelShowNYear;
    //QLabel* labelShowLunarDate;
    //QLabel* labelSpacer;
    //QLabel* labelScheduleTitle;
    //QLabel* labelSchedule;

    //QVBoxLayout* verlayoutWidgetRight;

    //QHBoxLayout* horLayoutGlobal;*/

    void sltShowPrevMonth();
    void sltShowNextMonth();
};



#endif // CALENDARWIDGET_H

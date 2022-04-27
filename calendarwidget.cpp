#include "calendarwidget.h"

#include "CalendarWidget.h"

DayLabel::DayLabel(QWidget* parent) :
    QLabel(parent)
{
    bSelect = false;
    m_nDay = 0;
    labelIcon = new QLabel(this);
    labelIcon->setFixedSize(QSize(12, 12));
    labelIcon->setPixmap(QPixmap("1.jpg"));
    labelIcon->move(0, 0);
    labelIcon->setVisible(false);
}

bool DayLabel::getBSelect() const
{
    return bSelect;
}

void DayLabel::setSelected(bool value)
{
    bSelect = value;
    QFont font("楷体", 20, 20);
    this->setFont(font);
    this->setStyleSheet(QString("background: #ffffff; border: 1px solid red; border-radius: 2px"));
}

void DayLabel::setColor(const int& type)
{
    // 设置控件属性类型
    this->setProperty("type", type);
    this->setSelected(CURRENT_DAY == type);

    // 其他月
    if ((PREV_MONTH_DAY == type) || (NEXT_MONTH_DAY == type)) {
        this->setStyleSheet("background: #ffffff; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3; color: #999999;");
        labelIcon->setVisible(false);
    }
    // 当前月
    else if (CURR_MONTH_DAY == type) {
        this->setStyleSheet("background: #ffffff; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3; color: #000000;");
    }
    // 周末
    else if (WEEKEND_DAY == type) {
        labelIcon->setVisible(false);
        this->setStyleSheet("background: #ffffff; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3; color: #ff0000;");
    }
}

/**
 * @brief DayLabel::showDay
 * @param nDay
 * @param strLunar
 * @param type
 */
void DayLabel::showDay(int nDay,int nMonth, int nYear, QString strLunar)
{
    QString strText = QString::number(nDay);
    this->m_nDay = nDay;
    this->m_nMonth = nMonth;
    this->m_nYear = nYear;

    if ("" != strLunar) {
        strText.append("\n");
        strText.append(strLunar);
    }

    this->setText(strText);
}

void DayLabel::enterEvent(QEvent* e)
{
    int nProperty = this->property("type").toInt();
    if (PREV_MONTH_DAY == nProperty || NEXT_MONTH_DAY == nProperty) return;

	QFont font("楷体", 20, 20);
	this->setFont(font);
    this->setStyleSheet("background: #c8b9a6; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3;");
    QLabel::enterEvent(e);
}

void DayLabel::leaveEvent(QEvent* e)
{
    int nProperty = this->property("type").toInt();
    if (PREV_MONTH_DAY == nProperty || NEXT_MONTH_DAY == nProperty) return;

    if (bSelect) {
        this->setStyleSheet("background: #ffffff; border: 1px solid red;");
    }
    else {
        this->setStyleSheet("background: #ffffff; border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3;");
    }
    QLabel::leaveEvent(e);
}

void DayLabel::mousePressEvent(QMouseEvent* e)
{
    qDebug() << this->text() << this->property("type").toInt() << m_nDay
        << m_nMonth << m_nYear;
    emit signalClicked(this->property("type").toInt(), m_nDay);

    //向主窗口传递消息
    QString strYear = QString::number(m_nYear);
    QString strMonth = QString::number(m_nMonth);
    if (strMonth.size() < 2)
    {
        strMonth = "0" + strMonth;
    }
    QString strDay = QString::number(m_nDay);
    if (strDay.size() < 2)
    {
        strDay = "0" + strDay;
    }
    QString str = strYear + "-" + strMonth + "-" + strDay;
    //qDebug()<<str;
    emit sendDayToCalendar(str);

    QLabel::mousePressEvent(e);
}

//void DayLabel::mouseDoubleClickEvent(QMouseEvent* e)
//{
//    //    qDebug() << "double";
//    int nProperty = this->property("type").toInt();
//    if (PREV_MONTH_DAY == nProperty || NEXT_MONTH_DAY == nProperty) return;
//
//    bool ok;
//    QString strText = "";
//    if (!m_strListPlan.isEmpty()) {
//        strText = m_strListPlan.at(1);
//    }
//
//    strText = QInputDialog::getText(this, tr("修改日程"),
//        tr("您的出行计划"), QLineEdit::Normal,
//        strText, &ok);
//    if (ok && !strText.isEmpty())
//        qDebug() << strText;
//    QLabel::mouseDoubleClickEvent(e);
//}


static const QString s_strWeek[] = {
    QObject::tr("周日"), QObject::tr("周一"), QObject::tr("周二"),
    QObject::tr("周三"), QObject::tr("周四"), QObject::tr("周五"),
    QObject::tr("周六"),
};

CalendarWidget::CalendarWidget(QWidget* parent)
    : QWidget(parent), m_nMonth(1)
{
    // 获取当前年月日
    m_nYear = QDate::currentDate().year();
    m_nMonth = QDate::currentDate().month();
    m_nDay = QDate::currentDate().day();

    initWidget();
    initDate();
}

int CalendarWidget::year() const
{
    return m_nYear;
}

void CalendarWidget::setYear(int nYear)
{
    m_nYear = nYear;
}

int CalendarWidget::month() const
{
    return m_nMonth;
}

void CalendarWidget::setMonth(int nMonth)
{
    m_nMonth = nMonth;
}

int CalendarWidget::day() const
{
    return m_nDay;
}

void CalendarWidget::setDay(int nDay)
{
    m_nDay = nDay;
}


void CalendarWidget::jumpTodate(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);

    initDate();

    QDate tmp(year,month,day);
    QString str=tmp.toString("yyyy-MM-dd");
    sendDayToTDL(str);
}

void CalendarWidget::initWidget()
{
    this->setMinimumSize(480, 380);
    this->setObjectName("widgetCalendar");

    verLayoutCalendar = new QVBoxLayout(this);
    verLayoutCalendar->setContentsMargins(2, 2, 2, 2);
    verLayoutCalendar->setSpacing(0);

    //! [2]
    widgetTitle = new QWidget(this);
    widgetTitle->setObjectName("widgetTitle");


    widgetTitle->setMinimumHeight(20);


    QString btnStyle2 =
        "QPushButton{\
                color: rgb(255, 255, 255);\
                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(166,164,208), stop:0.3 rgb(171,152,230), stop:1 rgb(152,140,220));\
                border:1px;\
                border-radius:5px; /*border-radius控制圆角大小*/\
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
    btnPrevMonth = new QPushButton(widgetTitle);
    btnPrevMonth->setText(tr("上月"));
    btnPrevMonth->setStyleSheet(btnStyle2);

    labelTitle = new QLabel(widgetTitle);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setObjectName("labelTitle");
    labelTitle->setText(tr("2016 年 04 月"));

     //btnNextMonth->resize(100,50);
    btnNextMonth = new QPushButton(widgetTitle);
    btnNextMonth->setText(tr("下月"));
    btnNextMonth->setStyleSheet(btnStyle2);

    horLayoutTitle = new QHBoxLayout(widgetTitle);
    horLayoutTitle->addWidget(btnPrevMonth);
    horLayoutTitle->addWidget(labelTitle, 1);
    horLayoutTitle->addWidget(btnNextMonth);

    verLayoutCalendar->addWidget(widgetTitle);

    connect(btnPrevMonth, &QPushButton::clicked, this, &CalendarWidget::sltShowPrevMonth);
    connect(btnNextMonth, &QPushButton::clicked, this,
        &CalendarWidget::sltShowNextMonth);
    ////! [2]

    ////! [3]
    widgetWeek = new QWidget(this);
    widgetWeek->setObjectName("widgetWeek");

    horLayoutWeek = new QHBoxLayout(widgetWeek);
    horLayoutWeek->setContentsMargins(0, 0, 0, 0);
    horLayoutWeek->setSpacing(0);

    for (int i = 0; i < Week; i++) {
        labelWeek[i] = new QLabel(widgetWeek);
        labelWeek[i]->setText(s_strWeek[i]);
        labelWeek[i]->setObjectName("labelWeek");
        labelWeek[i]->setMinimumHeight(30);
        labelWeek[i]->setAlignment(Qt::AlignCenter);
        if ((0 == (i % 7)) || (6 == (i % 7))) {
            labelWeek[i]->setProperty("weekend", true);
        }
        horLayoutWeek->addWidget(labelWeek[i]);
    }

    verLayoutCalendar->addWidget(widgetWeek);
    ////! [3]

    ////! [4]
    widgetBody = new QWidget(this);
    verLayoutCalendar->addWidget(widgetBody, 1);

    gridLayoutBody = new QGridLayout(widgetBody);
    gridLayoutBody->setHorizontalSpacing(0);
    gridLayoutBody->setVerticalSpacing(0);
    gridLayoutBody->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < 42; i++) {
        labelDay[i] = new DayLabel(widgetBody);
        labelDay[i]->setObjectName("labelDay");
        labelDay[i]->setAlignment(Qt::AlignCenter);
        labelDay[i]->setText(QString::number(i));
        if ((0 == (i % 7)) || (6 == (i % 7))) {
            labelDay[i]->setProperty("weekend", true);
        }
        gridLayoutBody->addWidget(labelDay[i], i / 7, i % 7);
        connect(labelDay[i], &DayLabel::signalClicked,
            this, &CalendarWidget::sltDayClicked);


        //将接收来自label的消息
        connect(labelDay[i], &DayLabel::sendDayToCalendar, [&](QString str)
            {
                emit sendDayToTDL(str);
                qDebug() << "sendDayToTDL";
            });
    }

    //labelDay[10]->setSelected(true);
    //! [4]
}


void CalendarWidget::initDate()
{
    // 首先判断当前月的第一天是星期几
    int nWeek = Date::getFirstDayOfWeek(m_nYear, m_nMonth);
    int nMonthDays = Date::getMonthDays(m_nYear, m_nMonth);
    // 上月天数
    int nPreMonDays = Date::getMonthDays(1 == m_nMonth ? m_nYear - 1 : m_nYear, 1 == m_nMonth ? 12 : m_nMonth - 1);

    // 显示当前年月
    labelTitle->setText(tr("%1 年 %2 月")
        .arg(m_nYear, 2, 10, QChar('0'))
        .arg(m_nMonth, 2, 10, QChar('0')));

    // 显示上月剩余天数
    if (0 == nWeek) {
        // 显示上月天数
        for (int i = 0; i < 7; i++) {
            labelDay[i]->showDay((nPreMonDays - 7 + i + 1), this->m_nMonth, this->m_nYear, "");
            labelDay[i]->setColor(PREV_MONTH_DAY);
        }
        // 显示下月天数
        for (int i = 0; i < (42 - nMonthDays - 7); i++) {
            labelDay[nMonthDays + 7 + i]->showDay((i + 1), this->m_nMonth, this->m_nYear, "");
            labelDay[nMonthDays + 7 + i]->setColor(NEXT_MONTH_DAY);
        }
    }
    else {
        for (int i = 0; i < nWeek; i++) {
            labelDay[i]->showDay((nPreMonDays - nWeek + i + 1), this->m_nMonth, this->m_nYear, "");
            labelDay[i]->setColor(PREV_MONTH_DAY);
        }

        // 显示下月天数
        for (int i = (nWeek + nMonthDays); i < 42; i++) {
            labelDay[i]->showDay((i - (nWeek + nMonthDays) + 1), this->m_nMonth, this->m_nYear, "");
            labelDay[i]->setColor(NEXT_MONTH_DAY);
        }
    }

    // 显示当前月
    int nProperty = 1;
    //QStringList strPlan;
    int index = 0;
    for (int i = nWeek; i < (nMonthDays + nWeek); i++) {
        index = 0 == nWeek ? (i + 7) : i;
        labelDay[index]->showDay(i - nWeek + 1, this->m_nMonth, this->m_nYear, Date::getLunarDate(m_nYear, m_nMonth, i - nWeek + 1));
        nProperty = ((0 == (i % 7)) || (6 == (i % 7))) ? WEEKEND_DAY : CURR_MONTH_DAY;
        labelDay[index]->setColor(nProperty);
    }

    // 显示当前天数
    if (m_nMonth == QDate::currentDate().month() && m_nYear == QDate::currentDate().year())
        labelDay[m_nDay + nWeek - 1]->setColor(CURRENT_DAY);
    // 发送更新信号
    Q_EMIT signalDayChanged();
}



/**
 * @brief CalendarWidget::sltDayClicked 点击响应
 * @param type  类型 0 表示上月 1表示下月
 * @param day  当前点击的天数
 */
void CalendarWidget::sltDayClicked(int type, int day)
{
    // 上月
    if (PREV_MONTH_DAY == type) {
        sltShowPrevMonth();
    }
    // 下月
    else if (NEXT_MONTH_DAY == type) {
        sltShowNextMonth();
    }
    // 当天/周末/当月天数都显示在右边，并转换成农历
    else if ((CURR_MONTH_DAY == type)
        || (WEEKEND_DAY == type)
        || (CURRENT_DAY == type)) {
        // 选中当天
        Q_EMIT signalDayClicked(day);
    }
}

/**
 * @brief CalendarWidget::sltShowPrevMonth 显示上月日期
 */
void CalendarWidget::sltShowPrevMonth()
{
    m_nMonth--;
    if (m_nMonth < 1) {
        m_nMonth = 12;
        m_nYear--;
    }

    initDate();
}


/**
 * @brief CalendarWidget::sltShowNextMonth 显示下月日期
 */
void CalendarWidget::sltShowNextMonth()
{
    m_nMonth++;
    if (m_nMonth > 12) {
        m_nMonth = 1;
        m_nYear++;
    }
    initDate();
}

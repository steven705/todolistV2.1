#include "TDLCalendar.h"


Window::Window(QWidget* parent) :
    QWidget(parent)
{
    //ui.setupUi(this);
    initWidget();
    initStyle();

    //接收来自子窗口的消息
    connect(calendar, &CalendarWidget::sendDayToTDL, [&](QString str) {
        emit sendDayToMain(str);
        });
}

Window::~Window()
{
}

void Window::initWidget()
{
    //! [1]
    this->resize(530, 700);
    calendar = new CalendarWidget(this);
    //! [1]

    //! [2]
    widgetRight = new QWidget(this);
    widgetRight->setObjectName("widgetRight");
    widgetRight->setMinimumSize(160, 100);

    labelShowToday = new QLabel(widgetRight);
    labelShowYear = new QLabel(widgetRight);
    labelShowWeek = new QLabel(widgetRight);
    labelShowDay = new QLabel(widgetRight);
    labelShowNYear = new QLabel(widgetRight);
    labelShowLunarDate = new QLabel(widgetRight);
    labelSpacer = new QLabel(widgetRight);
    ls2 = new QLabel(widgetRight);
    Ly = new QLabel(widgetRight);
    Lj = new QLabel(widgetRight);

    labelShowToday->setAlignment(Qt::AlignCenter);
    labelShowYear->setAlignment(Qt::AlignCenter);
    labelShowWeek->setAlignment(Qt::AlignCenter);
    labelShowDay->setAlignment(Qt::AlignCenter);
    labelShowNYear->setAlignment(Qt::AlignCenter);
    labelShowLunarDate->setAlignment(Qt::AlignCenter);
    //ls2->setAlignment(Qt::AlignCenter);
    Ly->setAlignment(Qt::AlignCenter);
    Lj->setAlignment(Qt::AlignCenter);
    labelSpacer->setFixedSize(widgetRight->width(), 2);
    ls2->setFixedSize(widgetRight->width(), 2);

    labelShowToday->setObjectName("labelCommon");
    labelShowWeek->setObjectName("labelCommon");
    labelShowYear->setObjectName("labelCommon");
    labelShowDay->setObjectName("labelShowDay");
    Ly->setObjectName("labelyiji");
    Lj->setObjectName("labelyiji");
    labelShowNYear->setObjectName("labelCommon");
    labelShowLunarDate->setObjectName("labelCommon");
    labelSpacer->setObjectName("labelSpacer");
    ls2->setObjectName("labelSpacer");

    labelShowToday->setText(QDateTime::currentDateTime().toString("yyyy 年 MM 月 dd日"));
    labelShowYear->setText(QDateTime::currentDateTime().toString("yyyy 年"));
    labelShowWeek->setText(QDate::currentDate().toString("ddd"));
    labelShowDay->setText(QDate::currentDate().toString("MM"));
    Ly->setText(QString("宜：%1").arg("Code"));
    Lj->setText(QString("忌：%1").arg("Sleep"));

    verlayoutWidgetRight = new QHBoxLayout(widgetRight);
    H1 = new QVBoxLayout(widgetRight);
    H1->addWidget(labelShowYear, 0, Qt::AlignLeft | Qt::AlignTop);
    H1->addWidget(labelShowNYear, 0, Qt::AlignLeft | Qt::AlignTop);
    H1->addStretch();
    H2 = new QVBoxLayout(widgetRight);
    H2->addStretch();
    H2->addWidget(labelShowWeek, 0, Qt::AlignLeft | Qt::AlignTop);
    //H2->addStretch();
    H2->addWidget(labelSpacer, 0, Qt::AlignLeft | Qt::AlignBottom);
    H2->addWidget(labelShowToday, 0, Qt::AlignLeft | Qt::AlignBottom);
    H2->addWidget(labelShowLunarDate, 0, Qt::AlignLeft | Qt::AlignBottom);

    H3 = new QVBoxLayout(widgetRight);
    H3->addWidget(Ly, 0, Qt::AlignCenter);
    H3->addWidget(ls2, 0, Qt::AlignCenter);
    H3->addWidget(Lj, 0, Qt::AlignCenter);
    verlayoutWidgetRight->setContentsMargins(0, 0, 0, 0);
    verlayoutWidgetRight->setSpacing(15);
    verlayoutWidgetRight->addWidget(labelShowDay);//月份
    verlayoutWidgetRight->addLayout(H1);
    verlayoutWidgetRight->addLayout(H2);
    verlayoutWidgetRight->addLayout(H3);


    //verlayoutWidgetRight->addWidget(labelShowYear);
    //verlayoutWidgetRight->addWidget(labelShowNYear);
    //verlayoutWidgetRight->addWidget(labelShowLunarDate);
    //verlayoutWidgetRight->addWidget(labelShowToday);
    //verlayoutWidgetRight->addWidget(labelShowWeek);



    //verlayoutWidgetRight->addWidget(labelSpacer, 0, Qt::AlignCenter);
    //verlayoutWidgetRight->addStretch(1);

    //! [2]



    //! [3]
    groupBoxBottom = new QGroupBox(this);

    labelYearJump = new QLabel(groupBoxBottom);
    labelMonthJump = new QLabel(groupBoxBottom);
    labelDayJump = new QLabel(groupBoxBottom);

    labelYearJump->setMinimumWidth(20);
    labelMonthJump->setMinimumWidth(20);
    labelDayJump->setMinimumWidth(20);

    labelYearJump->setObjectName("labelCommon");
    labelMonthJump->setObjectName("labelCommon");
    labelDayJump->setObjectName("labelCommon");

    labelYearJump->setText(tr("年:"));
    labelMonthJump->setText(tr("月:"));
    labelDayJump->setText(tr("日:"));
    ///

    editYearJump = new QLineEdit(groupBoxBottom);
    editMonthJump = new QLineEdit(groupBoxBottom);
    editDayJump = new QLineEdit(groupBoxBottom);

    editYearJump->setMaximumWidth(60);
    editMonthJump->setMaximumWidth(60);
    editDayJump->setMaximumWidth(60);

    editYearJump->setText(QString::number(QDate::currentDate().year()));
    editMonthJump->setText(QString::number(QDate::currentDate().month()));
    editDayJump->setText(QString::number(QDate::currentDate().day()));
    //

    btnDateJump = new QPushButton(groupBoxBottom);


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
    //设置样式

    btnDateJump->setText(tr("跳转至该日期"));
    btnDateJump->setStyleSheet(btnStyle2);
   // btnDateJump->resize(100, 50);
    btnToday = new QPushButton(groupBoxBottom);
    btnToday->setStyleSheet(btnStyle2);
    
    //设置样式

    btnToday->setText(tr("返回今天"));

    horLayoutJump = new QHBoxLayout(groupBoxBottom);
    horLayoutJump->setSpacing(10);
    horLayoutJump->addWidget(labelYearJump);
    horLayoutJump->addWidget(editYearJump);

    horLayoutJump->addWidget(labelMonthJump);
    horLayoutJump->addWidget(editMonthJump);

    horLayoutJump->addWidget(labelDayJump);
    horLayoutJump->addWidget(editDayJump);

    horLayoutJump->addStretch(1);
    horLayoutJump->addWidget(btnDateJump);
    horLayoutJump->addWidget(btnToday);

    //! [3]

    //! [4]
    verLayoutAll = new QVBoxLayout(this);
    verLayoutAll->setContentsMargins(10, 10, 10, 10);
    verLayoutAll->setSpacing(10);
    horLayoutWidget = new QVBoxLayout();
    horLayoutWidget->addWidget(widgetRight, 1);
    //horLayoutWidget->addWidget(calendar, 3, Qt::AlignCenter);
    verLayoutAll->addLayout(horLayoutWidget, 0);
    verLayoutAll->addWidget(groupBoxBottom, 0);
    verLayoutAll->addWidget(calendar, 0);
    verLayoutAll->setStretchFactor(widgetRight, 1);
    verLayoutAll->setStretchFactor(calendar, 3);



    //! [4]
    connect(calendar, &CalendarWidget::signalDayChanged, this, &Window::sltDayChanged);
    connect(calendar, &CalendarWidget::signalDayClicked, this, &Window::sltDayClicked);
    connect(btnDateJump, &QPushButton::clicked, this, &Window::sltDateJump);
    connect(btnToday, &QPushButton::clicked, this, &Window::sltBack2today);
    calendar->jumpTodate(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day());
}

/**
 * @brief CalendarWidget::initStyle 初始化样式
 */
void Window::initStyle()
{
    QString strStyle = "";

    strStyle += QString(".CalendarWidget {border: 1px solid #f0c9cf;}");
    //背景颜色
    strStyle += QString(".Window {background:rgb(152,140,220);}");

    strStyle += QString(".DayLabel{font: 100px; font-family: 楷体;}");
    strStyle += QString("QWidget#widgetCalendar{ background-color: white;}");
    

    //
    strStyle += QString("QWidget#widgetTitle{ background-color#497568;}");//#c8b9a6
    strStyle += QString("QWidget#widgetWeek{ background-color: #efefef;}");
    strStyle += QString("QLabel#labelTitle {border: none; font: bold 18px;}");
    strStyle += QString("QLabel#labelWeek {border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3; font: bold 12px;}");
    strStyle += QString("QLabel#labelDay[weekend=true],QLabel#labelWeek[weekend=true]{color: red;}");
    strStyle += QString("QLabel#labelDay {border-top: 1px solid #c3c3c3; border-left: 1px solid #c3c3c3; font-size: 14px;}");
    strStyle += QString("QLabel#labelShowDay {color: yellow; font: bold 64px;}");
    strStyle += QString("QLabel#labelyiji {color: yellow; font: bold 32px;}");
    strStyle += QString("QLabel#labelCommon {color: #ffffff;}");
    strStyle += QString("QLabel#labelSchedule {color: #ffffff; border: 1px solid #ffffff;}");
    strStyle += QString("QLabel#labelSpacer {border: 1px solid #ffffff;}");
    strStyle += QString("QLineEdit {border: 1px solid #ffffff; border-radius: 5px; font-size: 20px;}");

    this->setStyleSheet(strStyle);
}

static const QString Week_myf[] = {
    QObject::tr("周日"), QObject::tr("周一"), QObject::tr("周二"),
    QObject::tr("周三"), QObject::tr("周四"), QObject::tr("周五"),
    QObject::tr("周六"),
};

void Window::sltDayClicked(int nday)
{
    //labelShowDay->setText(QString("%1").arg(nday, 2, 10, QChar('0')));
    labelShowDay->setText(QString("%1月").arg(calendar->month()));
    labelShowToday->setText(QString("%1 年 %2 月 %3日").arg(QString::number(calendar->year()), QString::number(calendar->month()), QString::number(nday)));
    labelShowYear->setText(QString("%1 年").arg(QString::number(calendar->year())));
    qDebug() << calendar->month();
    labelShowWeek->setText(Week_myf[(nday +
        Date::getFirstDayOfWeek(calendar->year(), calendar->month()) - 1) % 7]);
    qDebug() << calendar->day();
    // 显示农历
    QString strLunar = Date::getLunarMonAndDay(calendar->year(), calendar->month(), nday);
    labelShowLunarDate->setText(tr("农历  %1").arg(strLunar));
    /*QString strLunar = Date::getLunarMonAndDay(year, month, day);
    labelShowLunarDate->setText(tr("农历  %1").arg(strLunar));*/
}

void Window::sltDayChanged()
{
    // 更新右边控件显示
    //labelShowDay->setText(QString("%1").arg(calendar->day(), 2, 10, QChar('0')));
    labelShowDay->setText(QString("%1月").arg(calendar->month()));
    //labelShowToday->setText(QString("%1 年 %2 月 %3日").arg(calendar->year(), calendar->month(), calendar->day()));
    /*labelShowWeek->setText(Week_myf[(nday +
        Date::getFirstDayOfWeek(calendar->year(), calendar->month()) - 1) % 7]);*/
    // 显示农历
    QString strLunar = Date::getLunarMonAndDay(calendar->year(), calendar->month(), calendar->day());
    labelShowLunarDate->setText(tr("农历  %1").arg(strLunar));
    labelShowNYear->setText(Date::getLunarTime(calendar->year()));
}

// 跳转日期
void Window::sltDateJump()
{
    int year = editYearJump->text().toInt();
    int month = editMonthJump->text().toInt();
    int day = editDayJump->text().toInt();
    int nMaxSet = 0;

    if ((year > 2040) || (year < 1970)) {
        QMessageBox::information(this, tr("提示"), tr("跳转年输入错误，请重新输入！"));
        editYearJump->setFocus();
        return;
    }

    if ((month > 12) || (month < 1)) {
        editMonthJump->setFocus();
        QMessageBox::information(this, tr("提示"), tr("跳转月输入错误，请重新输入！"));
        return;
    }

    if (2 == month) {
        nMaxSet = Date::isLoopYaer(year) ? 29 : 28;
    }
    else {
        nMaxSet = 31;
    }

    if ((day > nMaxSet) || (day < 1)) {
        editDayJump->setFocus();
        QMessageBox::information(this, tr("提示"), tr("跳转日输入错误，请重新输入！"));
        return;
    }
    // 跳转
    calendar->jumpTodate(year, month, day);
}

/**
 * @brief Window::sltBack2today 跳转至今天
 */
void Window::sltBack2today()
{
    int year = QDate::currentDate().year();
    int month = QDate::currentDate().month();
    int day = QDate::currentDate().day();

    // 跳转
    calendar->jumpTodate(year, month, day);
}

/**
 * @brief Window::sltShowPlans 显示日程
 * @param content
 * @return
 */
//void Window::sltShowPlans(const QString& content)
//{
//    labelShowPlan->setText(content);
//}

void Window::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


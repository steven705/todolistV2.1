#include "thingswidget.h"
#include "ui_thingswidget.h"

const int EventMaxNum = 50;

thingsWidget::thingsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::thingsWidget)
{
    ui->setupUi(this);
    this->resize(600,840);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(600, 840);
    ui->graphicsView->move(0, 0);
    ui->graphicsView->setStyleSheet("padding:0px;border:0px");
    // 将部件添加到布局管理器中
    layout = new QGraphicsLinearLayout;
    layout->setOrientation(Qt::Vertical);

    QFont font1("宋体", 15, 10);
    for (int i = 0; i < EventMaxNum; i++) {
        MyPushButton* btn = new MyPushButton;
        // 设置大小
        btn->setFont(font1);
        btn->setFixedSize(this->width() - 70, this->height() / 10);
        QGraphicsProxyWidget* pushButtonProxy = scene->addWidget(btn);//添加到场景中
        layout->addItem((QGraphicsWidget*)pushButtonProxy);//添加到布局当中
        vec_btn.push_back(btn);// 添加到vec_btn中，管理
        btn->setText(QString::number(i + 1));
        btn->setmyID(i);
        connect(btn, &MyPushButton::clicked, this, &thingsWidget::sendClickedToMain);
    }
   
    // 创建图形部件，设置其为一个顶层窗口，然后在其上应用布局
    form = new QGraphicsWidget;
    form->setLayout(layout);
    //将部件添加到场景中
    scene->addItem(form);
    //显示视图窗口
    ui->graphicsView->show();

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

    QFont font("华文行楷", 20, 15);
    ui->pushButton->resize(100, 100);
    ui->pushButton->move(470, 730);
    ui->pushButton->setText("+");
    ui->pushButton->setFont(font);
    ui->pushButton->setStyleSheet(btnStyle2);
    connect(ui->pushButton, &QPushButton::clicked,
        this, &thingsWidget::on_pushButton_clicked);
}

void thingsWidget::SetBtnText(const QVector<todolist_ui_inf>& SerchEvent) {
    int TupleNum = SerchEvent.size();
    for (int i = 0; i < EventMaxNum; i++)
    {
        vec_btn[i]->hide();
    }
	QString btnStyle1 =
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
	QString btnStyle2 =
		"QPushButton{\
                color: rgb(0, 0, 0);\
                background-color:#336699;\
		        border:1px; \
                border-radius:20px; /*border-radius控制圆角大小*/\
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
	QString btnStyle3 =
		"QPushButton{\
                color: rgb(255, 255, 255);\
                background-color :#CC3399;\
                border:1px;\
                border-radius:20px; /*border-radius控制圆角大小*/\
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

    for (int i = 0; i < TupleNum; i++) 
    {
        vec_btn[i]->setText(SerchEvent[i].EventTitle);

        //为它设置颜色
        if (SerchEvent[i].EventType==1)
        {
            vec_btn[i]->setStyleSheet(btnStyle1);
        }
		if (SerchEvent[i].EventType == 2)
		{
			vec_btn[i]->setStyleSheet(btnStyle2);
		}
		if (SerchEvent[i].EventType == 3)
		{
			vec_btn[i]->setStyleSheet(btnStyle3);
		}
	

        vec_btn[i]->show();
    }
}


thingsWidget::~thingsWidget()
{
    delete ui;
}

/// <summary>
/// 点击加号出现添加信息窗口
/// </summary>
void thingsWidget::on_pushButton_clicked()
{

    emit send(-1);
}



//将点击信号传递至主窗口
void thingsWidget::sendClickedToMain() {
    MyPushButton* tmp = (MyPushButton*)sender();
    emit send(tmp->getmyID());
}

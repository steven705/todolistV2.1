#include "barchart.h"
#include "ui_barchart.h"

barChart::barChart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::barChart)
{
    ui->setupUi(this);

	chart = new QChart();
	this->setFixedSize(1200, 800);
    chart->setTitle("Event statics");
	this->setWindowTitle("Things");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	
	

	QStringList categories;
    categories << "Last week" << "Currrent week" << "Next week";
	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	axisX->append(categories);

	chart->addAxis(axisX, Qt::AlignBottom);


	chartView = new QChartView(this);
	chartView->setChart(chart);
	chartView->resize(1200, 800);
	chartView->move(0, 00);
	chartView->setRenderHint(QPainter::Antialiasing);

}

void barChart::set(QVector<DT_EVENUM> f,QVector<DT_EVENUM> s,QVector<DT_EVENUM> t)
{
    QString str = f[0].day.toString("yyyy-MM-dd hh:mm:ss");
    QString str1 = t[0].day.toString("yyyy-MM-dd hh:mm:ss");
    QStringList list=str.split(" ");
    QStringList list1=str1.split(" ");
    this->setWindowTitle(list[0]+"~"+list1[0]);
	series = new QBarSeries(this);
    QBarSet *set0 = new QBarSet("Monday");
    QBarSet *set1 = new QBarSet("Tuesday");
    QBarSet *set2 = new QBarSet("Wednesday");
    QBarSet *set3 = new QBarSet("Thursday");
    QBarSet *set4 = new QBarSet("Friday");
    QBarSet *set5 = new QBarSet("Saturday");
    QBarSet *set6 = new QBarSet("Sunday");

	 *set0 << f[0].num << s[0].num << t[0].num ;
	 *set1 << f[1].num << s[1].num << t[1].num ;
	 *set2 << f[2].num << s[2].num << t[2].num;
	 *set3 << f[3].num << s[3].num << t[3].num ;
	 *set4 << f[4].num << s[4].num << t[4].num ;
	 *set5 << f[5].num << s[5].num << t[5].num;
	 *set6 << f[6].num << s[6].num << t[6].num ;





	
    series->clear();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);
    series->append(set6);
    series->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd); // 设置数据系列标签的位置于数据柱内测上方
    series->setLabelsVisible(true);

	chart->addSeries(series);

    
   

}
barChart::~barChart()
{
    delete ui;
}

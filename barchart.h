#ifndef BARCHART_H
#define BARCHART_H

#include <QDialog>
#include <QtWidgets/QTableView>
#include <QtCharts/QtCharts>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include"dbType.h"
#include<QVector>
#include<QPushButton>



namespace Ui {
class barChart;
}

class barChart : public QDialog
{
    Q_OBJECT



public:
    explicit barChart(QWidget *parent = nullptr);
      ~barChart();
    void set(QVector<DT_EVENUM> f,QVector<DT_EVENUM> s,QVector<DT_EVENUM> t);

private:
 

    

    Ui::barChart *ui;

	QChart* chart;
	QChartView* chartView;
	QBarSeries* series;
	
};

#endif // BARCHART_H

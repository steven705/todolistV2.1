#ifndef FOCUS_H
#define FOCUS_H

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
#include <QtMultimedia/QMediaPlayer>	
#include <QtMultimedia/QMediaPlaylist>
#include<QCloseEvent>
#include <QTimer>

namespace Ui {
class focus;
}

class focus : public QDialog
{
    Q_OBJECT

public:
    explicit focus(QWidget *parent = nullptr);
    ~focus();

	void set(QString n, QString BeginT,QString EndT, int ty)
    {
		if (ty == 3)
		{
			this->setStyleSheet("background-color :#CC3399;");
		}
		else if (ty == 2)
		{
			this->setStyleSheet("background-color :#336699;");
		}
		else
		{
			this->setStyleSheet("background-color :rgb(166,164,208);");
		}
        ET->setText(n);
        btToEt->setText(BeginT + "--" + EndT);
    }

private:
    QTimer* myTimer;
    Ui::focus *ui;
    QLabel* labelTime;
    QLabel* ET;
    QLabel* btToEt;
};

#endif // FOCUS_H

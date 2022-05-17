/********************************************************************************
** Form generated from reading UI file 'barchart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCHART_H
#define UI_BARCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_barChart
{
public:

    void setupUi(QDialog *barChart)
    {
        if (barChart->objectName().isEmpty())
            barChart->setObjectName(QString::fromUtf8("barChart"));
        barChart->resize(400, 300);

        retranslateUi(barChart);

        QMetaObject::connectSlotsByName(barChart);
    } // setupUi

    void retranslateUi(QDialog *barChart)
    {
        barChart->setWindowTitle(QCoreApplication::translate("barChart", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class barChart: public Ui_barChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCHART_H

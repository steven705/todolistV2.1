/********************************************************************************
** Form generated from reading UI file 'tdlcalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDLCALENDAR_H
#define UI_TDLCALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TDLCalendarClass
{
public:

    void setupUi(QWidget *TDLCalendarClass)
    {
        if (TDLCalendarClass->objectName().isEmpty())
            TDLCalendarClass->setObjectName(QStringLiteral("TDLCalendarClass"));
        TDLCalendarClass->resize(600, 400);

        retranslateUi(TDLCalendarClass);

        QMetaObject::connectSlotsByName(TDLCalendarClass);
    } // setupUi

    void retranslateUi(QWidget *TDLCalendarClass)
    {
        TDLCalendarClass->setWindowTitle(QApplication::translate("TDLCalendarClass", "TDLCalendar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TDLCalendarClass: public Ui_TDLCalendarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDLCALENDAR_H

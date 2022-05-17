/********************************************************************************
** Form generated from reading UI file 'eventremind.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTREMIND_H
#define UI_EVENTREMIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_eventRemind
{
public:

    void setupUi(QDialog *eventRemind)
    {
        if (eventRemind->objectName().isEmpty())
            eventRemind->setObjectName(QString::fromUtf8("eventRemind"));
        eventRemind->resize(400, 300);

        retranslateUi(eventRemind);

        QMetaObject::connectSlotsByName(eventRemind);
    } // setupUi

    void retranslateUi(QDialog *eventRemind)
    {
        eventRemind->setWindowTitle(QCoreApplication::translate("eventRemind", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eventRemind: public Ui_eventRemind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTREMIND_H

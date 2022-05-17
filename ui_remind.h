/********************************************************************************
** Form generated from reading UI file 'remind.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMIND_H
#define UI_REMIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_remind
{
public:

    void setupUi(QDialog *remind)
    {
        if (remind->objectName().isEmpty())
            remind->setObjectName(QString::fromUtf8("remind"));
        remind->resize(400, 300);

        retranslateUi(remind);

        QMetaObject::connectSlotsByName(remind);
    } // setupUi

    void retranslateUi(QDialog *remind)
    {
        remind->setWindowTitle(QCoreApplication::translate("remind", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class remind: public Ui_remind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMIND_H

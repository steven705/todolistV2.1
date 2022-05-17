/********************************************************************************
** Form generated from reading UI file 'focus.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOCUS_H
#define UI_FOCUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_focus
{
public:

    void setupUi(QDialog *focus)
    {
        if (focus->objectName().isEmpty())
            focus->setObjectName(QString::fromUtf8("focus"));
        focus->resize(400, 300);

        retranslateUi(focus);

        QMetaObject::connectSlotsByName(focus);
    } // setupUi

    void retranslateUi(QDialog *focus)
    {
        focus->setWindowTitle(QCoreApplication::translate("focus", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class focus: public Ui_focus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOCUS_H

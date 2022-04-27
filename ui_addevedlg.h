/********************************************************************************
** Form generated from reading UI file 'addevedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVEDLG_H
#define UI_ADDEVEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_addEVeDlg
{
public:

    void setupUi(QDialog *addEVeDlg)
    {
        if (addEVeDlg->objectName().isEmpty())
            addEVeDlg->setObjectName(QString::fromUtf8("addEVeDlg"));
        addEVeDlg->resize(400, 300);

        retranslateUi(addEVeDlg);

        QMetaObject::connectSlotsByName(addEVeDlg);
    } // setupUi

    void retranslateUi(QDialog *addEVeDlg)
    {
        addEVeDlg->setWindowTitle(QCoreApplication::translate("addEVeDlg", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addEVeDlg: public Ui_addEVeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVEDLG_H

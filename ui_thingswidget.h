/********************************************************************************
** Form generated from reading UI file 'thingswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THINGSWIDGET_H
#define UI_THINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thingsWidget
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;

    void setupUi(QWidget *thingsWidget)
    {
        if (thingsWidget->objectName().isEmpty())
            thingsWidget->setObjectName(QString::fromUtf8("thingsWidget"));
        thingsWidget->resize(409, 687);
        graphicsView = new QGraphicsView(thingsWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 100, 391, 581));
        pushButton = new QPushButton(thingsWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 580, 91, 71));

        retranslateUi(thingsWidget);

        QMetaObject::connectSlotsByName(thingsWidget);
    } // setupUi

    void retranslateUi(QWidget *thingsWidget)
    {
        thingsWidget->setWindowTitle(QCoreApplication::translate("thingsWidget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("thingsWidget", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thingsWidget: public Ui_thingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THINGSWIDGET_H

#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDialog>

namespace Ui {
class login;
}



class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void errorPrompt();

    void set(QString name);
signals:
    void send(QString name,QString password);
signals:
    void sendlogon();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H

#ifndef REMIND_H
#define REMIND_H

#include <QDialog>

namespace Ui {
class remind;
}

class remind : public QDialog
{
    Q_OBJECT

public:
    explicit remind(QWidget *parent = nullptr);
    ~remind();

private:
    Ui::remind *ui;
};

#endif // REMIND_H

#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include "ui_registerwindow.h"

class registerWindow : public QWidget, Ui::registerWindow
{
    Q_OBJECT

public:
    explicit registerWindow(QWidget *parent = 0);
    ~registerWindow();

private:
    Ui::registerWindow *ui;

private slots:
    void execRegister();
};

#endif // REGISTERWINDOW_H

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "chatwindow.h"

class loginWindow : public QWidget, Ui::loginWindow
{
    Q_OBJECT
    registerWindow regWindow;
    chatWindow cWindow;

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

private:
    Ui::loginWindow *ui;

private slots:
    void login();
    void openRegisterWindow();
};

#endif // LOGINWINDOW_H

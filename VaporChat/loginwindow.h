#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "chatwindow.h"
#include <QNetworkReply>

class loginWindow : public QWidget, Ui::loginWindow
{
    Q_OBJECT
    registerWindow regWindow;

public:
    loginWindow(QWidget *parent = 0);
    ~loginWindow();

private:
    Ui::loginWindow *ui;

private slots:
    void login();
    void openRegisterWindow();
public slots:
    void postRecieved(QNetworkReply* reply);
signals:
    void loginSuccessful();
};

#endif // LOGINWINDOW_H

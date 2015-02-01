#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include "ui_mainwindow.h"
#include "loginwindow.h"


class mainWindow : public QMainWindow, Ui::mainWindow
{
    Q_OBJECT
    QStringList friends;
    loginWindow logWin;

    public:
        mainWindow();
        ~mainWindow();

    private:
        Ui::mainWindow *ui;
        void getFriendList();
     public slots:
        void postRecieved(QNetworkReply* reply);

    /*signals:
        void message(const QString &username, const QString &text);
        void action(const QString &username, const QString &text);*/
    /*private slots:
        void textChangedSlot(const QString &newText);
        void sendClickedSlot();
        void loginWindow();
        void exiting();*/
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QHash>
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "openssl/rsa.h"


class mainWindow : public QMainWindow, Ui::mainWindow
{
    Q_OBJECT
    QStringList friends;
    loginWindow logWin;
    QHash<QString, chatWindow*> childWindows;

    public:
        mainWindow();
        ~mainWindow();

    private:
        Ui::mainWindow *ui;
        void getFriendList();
     public slots:
        void postRecieved(QNetworkReply* reply);
        void onItemClicked(QListWidgetItem* item);
        void swapLogin();

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

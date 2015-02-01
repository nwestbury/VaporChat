#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QLinkedList>
#include "ui_mainwindow.h"
<<<<<<< HEAD
#include "chatwindow.h"
=======
#include "loginwindow.h"

>>>>>>> b0f720e5ed41cbedb803242666fc7dccf8365e32

class mainWindow : public QMainWindow, Ui::mainWindow
{
    Q_OBJECT
    QStringList friends;
<<<<<<< HEAD
    QHash<QString, chatWindow*> childWindows;
=======
    loginWindow logWin;
>>>>>>> b0f720e5ed41cbedb803242666fc7dccf8365e32

    public:
        mainWindow();
        ~mainWindow();

    private:
        Ui::mainWindow *ui;
        void getFriendList();
     public slots:
        void postRecieved(QNetworkReply* reply);
        void onItemClicked(QListWidgetItem* item);

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

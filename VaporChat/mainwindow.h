#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class mainWindow : public QMainWindow, Ui::mainWindow
{
    Q_OBJECT
    QStringList friends;

    public:
        mainWindow();
        ~mainWindow();

    private:
        Ui::mainWindow *ui;
        void getFriendList();

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

#include <QApplication>
#include <QMessageBox>
#include <QListWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow()
{
    getFriendList();
    setupUi(this);

    for(int i=0; i<friends.size(); ++i){
        QListWidgetItem *item = new QListWidgetItem (QIcon(":img/online.png"), friends.at(i), friendList);
        friendList->addItem(item);
    }

    friendList->setSortingEnabled(true);
    //friendList->sortingEnabled(true);
}

mainWindow::~mainWindow()
{
}

void mainWindow::getFriendList(){
    friends << "Nico" << "James" << "Nathan";
}

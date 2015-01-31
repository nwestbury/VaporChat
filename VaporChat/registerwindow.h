#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>

namespace Ui {
class registerWindow;
}

class registerWindow : public QWidget
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

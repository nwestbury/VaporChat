/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *iconLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *logUsernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *logPasswordEdit;
    QLabel *errorLabel;
    QPushButton *loginButton;
    QPushButton *logRegisterButton;

    void setupUi(QWidget *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QStringLiteral("loginWindow"));
        loginWindow->resize(268, 360);
        loginWindow->setMinimumSize(QSize(268, 360));
        loginWindow->setMaximumSize(QSize(268, 360));
        verticalLayout = new QVBoxLayout(loginWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(15, 15, 15, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        iconLabel = new QLabel(loginWindow);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iconLabel->sizePolicy().hasHeightForWidth());
        iconLabel->setSizePolicy(sizePolicy);
        iconLabel->setMinimumSize(QSize(100, 100));
        iconLabel->setMaximumSize(QSize(100, 100));

        horizontalLayout_3->addWidget(iconLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(loginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        logUsernameEdit = new QLineEdit(loginWindow);
        logUsernameEdit->setObjectName(QStringLiteral("logUsernameEdit"));
        sizePolicy1.setHeightForWidth(logUsernameEdit->sizePolicy().hasHeightForWidth());
        logUsernameEdit->setSizePolicy(sizePolicy1);
        logUsernameEdit->setMinimumSize(QSize(0, 30));
        logUsernameEdit->setMaximumSize(QSize(16777215, 30));
        logUsernameEdit->setFont(font);

        horizontalLayout->addWidget(logUsernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(loginWindow);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(77, 30));
        label->setMaximumSize(QSize(16777215, 30));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        logPasswordEdit = new QLineEdit(loginWindow);
        logPasswordEdit->setObjectName(QStringLiteral("logPasswordEdit"));
        sizePolicy1.setHeightForWidth(logPasswordEdit->sizePolicy().hasHeightForWidth());
        logPasswordEdit->setSizePolicy(sizePolicy1);
        logPasswordEdit->setMinimumSize(QSize(0, 30));
        logPasswordEdit->setMaximumSize(QSize(16777215, 30));
        logPasswordEdit->setFont(font);
        logPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(logPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        errorLabel = new QLabel(loginWindow);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setMinimumSize(QSize(262, 20));
        errorLabel->setMaximumSize(QSize(262, 20));

        verticalLayout->addWidget(errorLabel);

        loginButton = new QPushButton(loginWindow);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy2);
        loginButton->setMinimumSize(QSize(0, 40));
        loginButton->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        loginButton->setFont(font1);

        verticalLayout->addWidget(loginButton);

        logRegisterButton = new QPushButton(loginWindow);
        logRegisterButton->setObjectName(QStringLiteral("logRegisterButton"));
        logRegisterButton->setMinimumSize(QSize(0, 40));
        logRegisterButton->setFont(font);

        verticalLayout->addWidget(logRegisterButton);


        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QWidget *loginWindow)
    {
        loginWindow->setWindowTitle(QApplication::translate("loginWindow", "Form", 0));
        iconLabel->setText(QString());
        label_2->setText(QApplication::translate("loginWindow", "Username:", 0));
        logUsernameEdit->setText(QString());
        label->setText(QApplication::translate("loginWindow", "Password:", 0));
        errorLabel->setText(QString());
        loginButton->setText(QApplication::translate("loginWindow", "Login", 0));
        logRegisterButton->setText(QApplication::translate("loginWindow", "Register", 0));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_registerWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *iconLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *regUsernameLabel;
    QLineEdit *regUsernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *regPasswordLabel;
    QLineEdit *regPasswordLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *regConfirmLabel;
    QLabel *regConPasswordLabel;
    QLineEdit *regConfirmPasswordEdit;
    QLabel *errorLabel;
    QPushButton *registerButton;

    void setupUi(QWidget *registerWindow)
    {
        if (registerWindow->objectName().isEmpty())
            registerWindow->setObjectName(QStringLiteral("registerWindow"));
        registerWindow->resize(275, 365);
        verticalLayout = new QVBoxLayout(registerWindow);
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        iconLabel = new QLabel(registerWindow);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iconLabel->sizePolicy().hasHeightForWidth());
        iconLabel->setSizePolicy(sizePolicy);
        iconLabel->setMinimumSize(QSize(123, 109));
        iconLabel->setMaximumSize(QSize(123, 109));
        iconLabel->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(iconLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        regUsernameLabel = new QLabel(registerWindow);
        regUsernameLabel->setObjectName(QStringLiteral("regUsernameLabel"));
        regUsernameLabel->setMinimumSize(QSize(0, 20));
        regUsernameLabel->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(12);
        regUsernameLabel->setFont(font);

        horizontalLayout->addWidget(regUsernameLabel);

        regUsernameEdit = new QLineEdit(registerWindow);
        regUsernameEdit->setObjectName(QStringLiteral("regUsernameEdit"));
        regUsernameEdit->setMinimumSize(QSize(170, 30));
        regUsernameEdit->setMaximumSize(QSize(170, 30));
        regUsernameEdit->setFont(font);

        horizontalLayout->addWidget(regUsernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        regPasswordLabel = new QLabel(registerWindow);
        regPasswordLabel->setObjectName(QStringLiteral("regPasswordLabel"));
        regPasswordLabel->setMinimumSize(QSize(0, 20));
        regPasswordLabel->setMaximumSize(QSize(16777215, 20));
        regPasswordLabel->setFont(font);

        horizontalLayout_2->addWidget(regPasswordLabel);

        regPasswordLineEdit = new QLineEdit(registerWindow);
        regPasswordLineEdit->setObjectName(QStringLiteral("regPasswordLineEdit"));
        sizePolicy.setHeightForWidth(regPasswordLineEdit->sizePolicy().hasHeightForWidth());
        regPasswordLineEdit->setSizePolicy(sizePolicy);
        regPasswordLineEdit->setMinimumSize(QSize(170, 30));
        regPasswordLineEdit->setMaximumSize(QSize(170, 30));
        regPasswordLineEdit->setFont(font);
        regPasswordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(regPasswordLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        regConfirmLabel = new QLabel(registerWindow);
        regConfirmLabel->setObjectName(QStringLiteral("regConfirmLabel"));
        regConfirmLabel->setFont(font);

        verticalLayout_2->addWidget(regConfirmLabel);

        regConPasswordLabel = new QLabel(registerWindow);
        regConPasswordLabel->setObjectName(QStringLiteral("regConPasswordLabel"));
        regConPasswordLabel->setFont(font);

        verticalLayout_2->addWidget(regConPasswordLabel);


        horizontalLayout_3->addLayout(verticalLayout_2);

        regConfirmPasswordEdit = new QLineEdit(registerWindow);
        regConfirmPasswordEdit->setObjectName(QStringLiteral("regConfirmPasswordEdit"));
        sizePolicy.setHeightForWidth(regConfirmPasswordEdit->sizePolicy().hasHeightForWidth());
        regConfirmPasswordEdit->setSizePolicy(sizePolicy);
        regConfirmPasswordEdit->setMinimumSize(QSize(170, 30));
        regConfirmPasswordEdit->setMaximumSize(QSize(170, 30));
        regConfirmPasswordEdit->setFont(font);
        regConfirmPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(regConfirmPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        errorLabel = new QLabel(registerWindow);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        sizePolicy.setHeightForWidth(errorLabel->sizePolicy().hasHeightForWidth());
        errorLabel->setSizePolicy(sizePolicy);
        errorLabel->setMinimumSize(QSize(262, 20));
        errorLabel->setMaximumSize(QSize(262, 20));

        verticalLayout->addWidget(errorLabel);

        registerButton = new QPushButton(registerWindow);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        sizePolicy.setHeightForWidth(registerButton->sizePolicy().hasHeightForWidth());
        registerButton->setSizePolicy(sizePolicy);
        registerButton->setMinimumSize(QSize(262, 30));
        registerButton->setFont(font);

        verticalLayout->addWidget(registerButton);


        retranslateUi(registerWindow);

        QMetaObject::connectSlotsByName(registerWindow);
    } // setupUi

    void retranslateUi(QWidget *registerWindow)
    {
        registerWindow->setWindowTitle(QApplication::translate("registerWindow", "Register", 0));
        iconLabel->setText(QString());
        regUsernameLabel->setText(QApplication::translate("registerWindow", "Username:", 0));
        regPasswordLabel->setText(QApplication::translate("registerWindow", "Password:", 0));
        regConfirmLabel->setText(QApplication::translate("registerWindow", "Confirm", 0));
        regConPasswordLabel->setText(QApplication::translate("registerWindow", "Password:", 0));
        regConfirmPasswordEdit->setText(QString());
        errorLabel->setText(QString());
        registerButton->setText(QApplication::translate("registerWindow", "Register", 0));
    } // retranslateUi

};

namespace Ui {
    class registerWindow: public Ui_registerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H

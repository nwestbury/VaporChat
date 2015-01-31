#-------------------------------------------------
#
# Project created by QtCreator 2015-01-31T12:06:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VaporChat
TEMPLATE = app

win32-msvc*: {
    INCLUDEPATH += C:/OpenSSL-Win64/include
    LIBS += -L"C:/OpenSSL-Win64/lib" -llibeay32
} else {
    LIBS += -lssl -lcrypto
}

SOURCES += main.cpp\
        mainwindow.cpp \
    networking.cpp

HEADERS  += mainwindow.h \
    networking.h

FORMS    += mainwindow.ui

RESOURCES += \
    ressources.qrc

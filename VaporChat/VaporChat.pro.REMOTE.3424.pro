#-------------------------------------------------
#
# Project created by QtCreator 2015-01-31T12:06:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VaporChat
TEMPLATE = app

win32{
    INCLUDEPATH += C:/OpenSSL-Win64/include
    LIBS += -L"C:/OpenSSL-Win64/lib" -llibeay32
} else {
    LIBS += -lssl -lcrypto
}

SOURCES += main.cpp\
        mainwindow.cpp\
        registerwindow.cpp \
    loginwindow.cpp \
    networking.cpp \
    crypto.cpp

HEADERS  += mainwindow.h\
         registerwindow.h \
    loginwindow.h \
    networking.h \
    crypto.h

FORMS    += mainwindow.ui\
         registerwindow.ui \
    loginwindow.ui

RESOURCES += \
    ressources.qrc

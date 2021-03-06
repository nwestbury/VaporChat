#-------------------------------------------------
#
# Project created by QtCreator 2015-01-31T12:06:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VaporChat
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

win32{
    INCLUDEPATH += C:/OpenSSL-Win64/include
    LIBS += -L"C:/OpenSSL-Win64/lib" -llibeay32
} else {
    LIBS += -lssl -lcrypto
}

SOURCES += main.cpp\
        mainwindow.cpp\
        registerwindow.cpp\
        loginwindow.cpp\
	networking.cpp \
        crypto.cpp \
        chatwindow.cpp \
    global.cpp

HEADERS  += mainwindow.h\
         registerwindow.h\
         loginwindow.h \
    	 chatwindow.h\
	 networking.h\
    	 crypto.h \
    global.h

FORMS    += mainwindow.ui\
         registerwindow.ui\
         loginwindow.ui \
    	 chatwindow.ui

RESOURCES += \
    ressources.qrc

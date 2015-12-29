#-------------------------------------------------
#
# Project created by QtCreator 2015-12-24T23:58:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = D2GUI
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    sbetalayout.cpp \
    sprojectexplorer.cpp \
    scrollarea.cpp \
    foldline.cpp \
    layout/flowlayout.cpp \
    layout/qclicklabel.cpp \
    qsomething.cpp \
    layout/qsizewidget.cpp

HEADERS  += \
    sbetalayout.h \
    sprojectexplorer.h \
    scrollarea.h \
    foldline.h \
    layout/flowlayout.h \
    layout/qclicklabel.h \
    qsomething.h \
    layout/qsizewidget.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../../../Qt/arrow-opened.png

RESOURCES += \
    style.qrc

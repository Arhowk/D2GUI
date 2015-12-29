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
    smainlayout.cpp \
    layout/flowlayout.cpp \
    layout/qclicklabel.cpp \
    layout/qsizewidget.cpp \
    layout/scrollarea.cpp \
    layout_shared/foldline.cpp \
    project_explorer/sprojectexplorer.cpp \

HEADERS  += \
    smainlayout.h \
    layout/flowlayout.h \
    layout/qclicklabel.h \
    layout/qsizewidget.h \
    layout/scrollarea.h \
    layout_shared/foldline.h \
    project_explorer/sprojectexplorer.h \

FORMS    += mainwindow.ui

DISTFILES += \
    ../../../Qt/arrow-opened.png

RESOURCES += \
    style.qrc

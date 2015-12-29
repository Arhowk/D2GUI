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
    ui/layout/flowlayout.cpp \
    ui/layout/qclicklabel.cpp \
    ui/layout/scrollarea.cpp \
    ui/layout_shared/foldline.cpp \
    ui/notes/snotesarea.cpp \
    ui/project_explorer/sprojectexplorer.cpp \
    ui/trigger_editor/striggereditor.cpp

HEADERS  += \
    smainlayout.h \
    ui/layout/flowlayout.h \
    ui/layout/qclicklabel.h \
    ui/layout/scrollarea.h \
    ui/layout_shared/foldline.h \
    ui/notes/snotesarea.h \
    ui/project_explorer/sprojectexplorer.h \
    ui/trigger_editor/striggereditor.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../../../Qt/arrow-opened.png

RESOURCES += \
    style.qrc

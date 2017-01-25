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
    model/file/dguireader.cpp \
    model/triggers/dguifile.cpp \
    model/triggers/dguiline.cpp \
    model/triggers/dguiargument.cpp \
    model/triggers/dguikeydatabase.cpp \
    model/triggers/dguiproject.cpp \
    ui/layout_shared/stoolbar.cpp \
    model/triggers/dguistructurevalue.cpp \
    ui/lineselector.cpp \
    ui/working/striggereditor.cpp \
    ui/dialogs/argument_selector/sargumentselector.cpp \
    ui/working/sobjecteditor.cpp \
    ui/working/sitemeditor.cpp \
    model/objects/dgobject.cpp \
    model/objects/dgobjectitem.cpp \
    model/objects/dgobjectdataset.cpp

HEADERS  += \
    smainlayout.h \
    ui/layout/flowlayout.h \
    ui/layout/qclicklabel.h \
    ui/layout/scrollarea.h \
    ui/layout_shared/foldline.h \
    ui/notes/snotesarea.h \
    ui/project_explorer/sprojectexplorer.h \
    model/file/dguireader.h \
    model/triggers/dguifile.h \
    model/triggers/dguiline.h \
    model/triggers/dguiargument.h \
    model/triggers/dguikeydatabase.h \
    model/triggers/dguiproject.h \
    ui/layout_shared/stoolbar.h \
    model/triggers/dguistructurevalue.h \
    ui/lineselector.h \
    ui/working/striggereditor.h \
    ui/dialogs/argument_selector/sargumentselector.h \
    ui/working/sobjecteditor.h \
    ui/working/sitemeditor.h \
    model/objects/dgobject.h \
    model/objects/dgobjectitem.h \
    model/objects/dgobjectdataset.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../../../Qt/arrow-opened.png

RESOURCES += \
    style.qrc

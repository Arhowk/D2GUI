#include "stoolbar.h"
#include <Qt>
#include <QAction>
#include <QIcon>
#include <QMainWindow>
#include <QLabel>
#include <QToolBar>
#include <QObject>

SToolbar::SToolbar()
{

}

void SToolbar::newFile()
{
    qDebug("New File");
}

void SToolbar::CreateToolbar(QMainWindow *window)
{
    SToolbar *listener = new SToolbar();

    //Init the icons

    QAction *newAct = new QAction(QIcon(":/images/page.png"), QObject::tr("&New"), window);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(QObject::tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), listener, SLOT(newFile()));

    QAction *openAct = new QAction(QIcon(":/images/folder.png"), QObject::tr("&Open..."), window);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(QObject::tr("Open an existing file"));
   // connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    QAction *saveAct = new QAction(QIcon(":/images/disk.png"), QObject::tr("&Save"), window);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(QObject::tr("Save the document to disk"));
    //connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    QAction *cutAct = new QAction(QIcon(":/images/cut.png"), QObject::tr("Cu&t"), window);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(QObject::tr("Cut the current selection's contents to the "
                            "clipboard"));
    //connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

    QAction *copyAct = new QAction(QIcon(":/images/page_copy.png"), QObject::tr("&Copy"), window);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(QObject::tr("Copy the current selection's contents to the "
                             "clipboard"));
    //connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

    QAction *pasteAct = new QAction(QIcon(":/images/paste_plain.png"), QObject::tr("&Paste"), window);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(QObject::tr("Paste the clipboard's contents into the current "
                              "selection"));
    //connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));


    //Init the toolbars
    QToolBar *toolbar = window->addToolBar(QObject::tr("File"));
    toolbar->addAction(newAct);
    toolbar->addAction(openAct);
    toolbar->addAction(saveAct);

    QToolBar *editToolBar = window->addToolBar(QObject::tr("Edit"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}


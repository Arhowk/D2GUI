#include <QPushButton>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPalette>
#include <QGroupBox>
#include <QSplitter>
#include <QTextEdit>
#include <QList>

#include "smainlayout.h"
#include "ui/layout_shared/foldline.h"
#include "ui/project_explorer/sprojectexplorer.h"
#include "ui/trigger_editor/striggereditor.h"
#include "ui/notes/snotesarea.h"

SMainLayout::y(){
    //qDebug("Size: %d", projectExplorer->height());
}

SMainLayout::setupMenu(QMainWindow * wndr)
{
    //QMenuBar * menu = this->parent()->parent()->menu
   QMenu *menu = wndr->menuBar()->addMenu(tr("&File"));

    QAction *action = menu->addAction(tr("Save layout..."));
    //connect(action, SIGNAL(triggered()), this, SLOT(saveLayout()));

   // action = menu->addAction(tr("Load layout..."));
    //connect(action, SIGNAL(triggered()), this, SLOT(loadLayout()));

}


SMainLayout::SMainLayout(QWidget *parent, QMainWindow * parentWindow) : QSplitter(Qt::Horizontal, parent)
{
    //this->setupMenu(parentWindow);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout * qvbxl = new QVBoxLayout;
    QGroupBox * qgp = new QGroupBox("");
    qgp->setStyleSheet("background-color: white;");
    qgp->setLayout(qvbxl);
    qvbxl->addWidget(new SProjectExplorer());

    addWidget(qgp);


    QSplitter * commentsAndTriggers = new QSplitter(Qt::Vertical);


    qvbxl = new QVBoxLayout;
    qgp = new QGroupBox("");
    qvbxl->setMargin(0);
    qgp->setStyleSheet("background-color: white;");
    qgp->setLayout(qvbxl);
    qvbxl->addWidget(new QTextEdit());
    commentsAndTriggers->addWidget(qgp);

    qvbxl = new QVBoxLayout;
    qgp = new QGroupBox("");
    qvbxl->setMargin(0);
    qgp->setStyleSheet("background-color: white;");
    qgp->setLayout(qvbxl);
    qvbxl->addWidget(new QTextEdit());
    commentsAndTriggers->addWidget(qgp);

    addWidget(commentsAndTriggers);


    QList<int> list;
    list << 300 << (1920-300);
    this->setSizes(list);
    /*
     * Old grid one
     */
    /*
    //Init
    parent->setWindowTitle(tr("hello world"));

    QVBoxLayout * qvbxl = new QVBoxLayout;
    QGroupBox * qgp = new QGroupBox("");
    qgp->setStyleSheet("background-color: white;");
    qgp->setFixedWidth(250);
    qgp->setLayout(qvbxl);
    setSpacing(2);
    setMargin(4);

    //Initialize the project explorer
    projectExplorer = new SProjectExplorer();
    projectExplorer->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    //Initialize the trigger area

    //Initialize the notes seciton

    //Tie it together
    qvbxl->addWidget(projectExplorer);

    addWidget(qgp, 0, 0,2,1);
    addWidget( new FoldLine(), 0, 1 );
    addWidget( new QPushButton( "baz" ), 1, 1 );

    setRowStretch(0, 9); // 10% for top row
    setRowStretch(1, 1); // 80% for middle row
    setRowMinimumHeight(0, 20); // 20px for top row*/

/*
    QTimer * timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(y()));
    timer->start(1000); //time specified in ms
    timer->setSingleShot(false);*/
}


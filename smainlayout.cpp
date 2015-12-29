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

#include "smainlayout.h"
#include "layout_shared/foldline.h"
#include "project_explorer/sprojectexplorer.h"

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

SMainLayout::SMainLayout(QWidget *parent, QMainWindow * parentWindow) : QGridLayout(parent)
{
    QWidget wnd;
    QTextEdit *editor1 = new QTextEdit;
    QTextEdit *editor2 = new QTextEdit;
    QTextEdit *editor3 = new QTextEdit;

    QSplitter *split1 = new QSplitter;
    QSplitter *split2 = new QSplitter;

    QVBoxLayout *layout = new QVBoxLayout;

    QWidget *container = new QWidget;
    QVBoxLayout *container_layout = new QVBoxLayout;

    split1->addWidget(editor1);
    split1->addWidget(editor2);

    container_layout->addWidget(split1);
    container->setLayout(container_layout);

    split2->setOrientation(Qt::Vertical);
    split2->addWidget(container);
    split2->addWidget(editor3);

    layout->addWidget(split2);

    wnd.setLayout(layout);
    addWidget(&wnd,0,0);

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
    this->setupMenu(parentWindow);
}


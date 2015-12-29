#include "sbetalayout.h"
#include "sprojectexplorer.h"
#include <QPushButton>
#include <QTimer>
#include "foldline.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPalette>
#include <QGroupBox>
SBetaLayout::y(){
    //qDebug("Size: %d", projectExplorer->height());
}

SBetaLayout::setupMenu(QMainWindow * wndr)
{
    //QMenuBar * menu = this->parent()->parent()->menu
   QMenu *menu = wndr->menuBar()->addMenu(tr("&File"));

    QAction *action = menu->addAction(tr("Save layout..."));
    //connect(action, SIGNAL(triggered()), this, SLOT(saveLayout()));

   // action = menu->addAction(tr("Load layout..."));
    //connect(action, SIGNAL(triggered()), this, SLOT(loadLayout()));

}

SBetaLayout::SBetaLayout(QWidget *parent, QMainWindow * parentWindow) : QGridLayout(parent)
{
    parent->setWindowTitle(tr("hello world"));
    projectExplorer = new SProjectExplorer();
    QVBoxLayout * qvbxl = new QVBoxLayout;
    QGroupBox * qgp = new QGroupBox("");
    qgp->setStyleSheet("background-color: white;");
    qgp->setFixedWidth(250);
    qvbxl->addWidget(projectExplorer);
    qgp->setLayout(qvbxl);
    QPalette p = qgp->palette();
    p.setColor(QPalette::Dark, Qt::black);
    qgp->setPalette(p);
    addWidget(qgp, 0, 0,2,1);
    addWidget( new FoldLine(), 0, 1 );
    addWidget( new QPushButton( "baz" ), 1, 1 );
    projectExplorer->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
    setRowStretch(0, 9); // 10% for top row
    setRowStretch(1, 1); // 80% for middle row
    qDebug("%d", projectExplorer->height());
    setRowMinimumHeight(0, 20); // 20px for top row

    auto y = [] ()
    {
        return 0;
    };

    QTimer * timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(y()));
    timer->start(1000); //time specified in ms
    timer->setSingleShot(false);
    setSpacing(2);
    setMargin(4);
    this->setupMenu(parentWindow);
}


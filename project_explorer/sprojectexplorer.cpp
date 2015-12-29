#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QTimer>
#include <QGridLayout>

#include "sprojectexplorer.h"
#include "layout_shared/foldline.h"
#include "layout/qclicklabel.h"

SProjectExplorer::SProjectExplorer(QWidget *parent) : QWidget(parent)
{
    flow = new FlowLayout();
    lbl = new QLabel();
    lbl->setText("Hello World");
    flow->addWidget(new FoldLine());
    flow->addWidget(new FoldLine());
    flow->addWidget(new FoldLine());
    flow->addWidget(new FoldLine());
    //flow->addWidget(new QLabel(tr("ggg fags")));
    setLayout(flow);

    FoldLine * f = new FoldLine();
    FoldLine * f2 = new FoldLine();
    FoldLine * f3 =  new FoldLine();
    FoldLine * f4 = new FoldLine();
    f2->AddChild(f3);
    f->AddChild(f2);
    f->AddChild(f4);
    flow->addWidget(f);


    QTimer * timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(y()));
    timer->start(1000); //time specified in ms
    timer->setSingleShot(false);
    flow->setMargin(0);

}

SProjectExplorer::y()
{
   // f = f + 1;
    //QFont fb( "Arial", f, QFont::Bold);
   // lbl->setFont( fb);
}


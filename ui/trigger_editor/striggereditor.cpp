#include <QtDebug>
#include <QGridLayout>

#include "ui/layout/flowlayout.h"
#include "ui/trigger_editor/striggereditor.h"
#import "ui/layout_shared/foldline.h"
STriggerEditor *STriggerEditor::instance = 0;

STriggerEditor* STriggerEditor::getInstance(){
    return STriggerEditor::instance;
}

STriggerEditor::STriggerEditor(QWidget *parent) : QWidget(parent)
{
   // QGridLayout * gridLayout = new QGridLayout;
    STriggerEditor::instance = this;
    FlowLayout * f = new FlowLayout;
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    FoldLine * masterFoldLine = new FoldLine();
    masterFoldLine->SetText(tr("Untitled Trigger 01"));
    masterFoldLine->SetImage("page");

    FoldLine * events = new FoldLine();
    events->SetText(tr("Events"));
    events->SetImage("bell");

    FoldLine * towerKilled = new FoldLine();
    towerKilled->SetText(tr("DOTA- A tower from team <a href=\"http:\\www.google.com\">(Any Team)</a> was destroyed"));
    towerKilled->SetImage(tr("rainbow"));
    towerKilled->textLabel->shouldHighlight = false;
    towerKilled->textLabel->setOpenExternalLinks(false);
    connect(towerKilled->textLabel, SIGNAL(linkActivated(QString)), this, SLOT(onLinkClicked(QString)));

    FoldLine * conditions = new FoldLine();
    conditions->SetText(tr("Conditions"));
    conditions->SetImage("help");

    FoldLine * wasDenial = new FoldLine();
    wasDenial->SetText(tr("Entities- Specified killing was a denial"));
    wasDenial->SetImage(tr("rainbow"));

    FoldLine * actions = new FoldLine();
    actions->SetText(tr("Actions"));
    actions->SetImage("lightning");

    events->AddChild(towerKilled);
    conditions->AddChild(wasDenial);

    masterFoldLine->AddChild(events);
    masterFoldLine->AddChild(conditions);
    masterFoldLine->AddChild(actions);

    f->addWidget(masterFoldLine);

   // gridLayout->addWidget(f,0,0);
    setLayout(f);
}

STriggerEditor::onLinkClicked(QString str)
{
    qDebug("Hello");
    qDebug() << str;
}


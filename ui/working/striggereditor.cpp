#include <QtDebug>
#include <QGridLayout>

#include "ui/layout/flowlayout.h"
#include "ui/working/striggereditor.h"
#include "ui/layout_shared/foldline.h"

#include "model/triggers/dguiline.h"
#include "model/triggers/dguikeydatabase.h"

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

    FoldLine * conditions = new FoldLine();
    conditions->SetText(tr("Conditions"));
    conditions->SetImage("help");

    FoldLine * actions = new FoldLine();
    actions->SetText(tr("Actions"));
    actions->SetImage("lightning");
    /*
    FoldLine * towerKilled = new FoldLine();
    towerKilled->SetText(tr("DOTA- A tower from team <a href=\"http:\\www.google.com\">(Any Team)</a> was destroyed"));
    towerKilled->SetImage(tr("rainbow"));
    towerKilled->textLabel->shouldHighlight = false;
    towerKilled->textLabel->setOpenExternalLinks(false);
    connect(towerKilled->textLabel, SIGNAL(linkActivated(QString)), this, SLOT(onLinkClicked(QString)));


    FoldLine * wasDenial = new FoldLine();
    wasDenial->SetText(tr("Entities- Specified killing was a denial"));
    wasDenial->SetImage(tr("rainbow"));


    events->AddChild(towerKilled);
    conditions->AddChild(wasDenial);
    */



    masterFoldLine->AddChild(events, false);
    masterFoldLine->AddChild(conditions, false);
    masterFoldLine->AddChild(actions,false);

    f->addWidget(masterFoldLine);
    DGUILine* firstEvent = DGUIKeyDatabase::getLine(0, 0);

    FoldLine * evt1 = new FoldLine();
    evt1->SetText(firstEvent->toTriggerString());

    evt1->SetImage(firstEvent->getIcon());

    events->AddChild(evt1,false);

   // gridLayout->addWidget(f,0,0);
    setLayout(f);
}

void STriggerEditor::onLinkClicked(QString str)
{
    qDebug("Hello");
    qDebug() << str;
}

void STriggerEditor::changeFile(QString str)
{
    qDebug("Hello");
    qDebug() << str;
}


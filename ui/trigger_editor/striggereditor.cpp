#include <QGridLayout>

#include "ui/layout/flowlayout.h"
#include "ui/trigger_editor/striggereditor.h"
#import "ui/layout_shared/foldline.h"

STriggerEditor::STriggerEditor(QWidget *parent) : QWidget(parent)
{
   // QGridLayout * gridLayout = new QGridLayout;

    FlowLayout * f = new FlowLayout;
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    FoldLine * masterFoldLine = new FoldLine();
    masterFoldLine->SetText(tr("Untitled Trigger 01"));
    masterFoldLine->SetImage("page");

    FoldLine * events = new FoldLine();
    events->SetText(tr("Events"));
    events->SetImage("bell");

    FoldLine * towerKilled = new FoldLine();
    towerKilled->SetText(tr("DOTA- A tower from team (Any Team) was destroyed"));
    towerKilled->SetImage(tr("rainbow"));

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


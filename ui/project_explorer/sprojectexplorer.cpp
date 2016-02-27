#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QTimer>
#include <QList>
#include <QGridLayout>
#include <QJsonArray>
#include <QMap>

#include "ui/project_explorer/sprojectexplorer.h"
#include "model/triggers/dguistructurevalue.h"
#include "ui/layout_shared/foldline.h"
#include "ui/layout/qclicklabel.h"

SProjectExplorer::SProjectExplorer(QWidget *parent) : QWidget(parent)
{
    flow = new FlowLayout();
    /*
    lbl = new QLabel();
    lbl->setText("Hello World");
    flow->addWidget(new FoldLine());
    flow->addWidget(new FoldLine());
    flow->addWidget(new FoldLine());
    flow->addWidget(new FoldLine());
    //flow->addWidget(new QLabel(tr("ggg fags")));

    FoldLine * f = new FoldLine();
    FoldLine * f2 = new FoldLine();
    FoldLine * f3 =  new FoldLine();
    FoldLine * f4 = new FoldLine();
    f2->AddChild(f3);
    f->AddChild(f2);
    f->AddChild(f4);
    flow->addWidget(f);*/

    setLayout(flow);

    QTimer * timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(y()));
    timer->start(1000); //time specified in ms
    timer->setSingleShot(false);
    flow->setMargin(0);
    this->loadFolder(new QString("D:/Code/Qt/D2GUI/DOTA Project/content/d2guitest/scripts"));
    qDebug("Done here!");

}

SProjectExplorer::loadFolder(QString * dir){
    return SProjectExplorer::loadFolder(new DGUIProject(dir));
}

SProjectExplorer::loadSubFolder(QString path, FoldLine *line, DGUIStructureValue* obj){
    foreach(QString key, obj->children->keys()){
        if(key == "#childrenOfThisParentKappaKappaChameleon"){
            DGUIStructureValue *arr = obj->children->operator []("#childrenOfThisParentKappaKappaChameleon");
            //QList<QString>* arrRaw= arr->superChildList
            foreach(QString value, *(arr->superChildList)){
                FoldLine *newLine = new FoldLine();
                newLine->SetImage("page");
                newLine->SetText(value);\
                newLine->SetHasCollapse(false);
                line->AddChild(newLine);
            }
        }else{
            FoldLine *newLine = new FoldLine();
            newLine->SetText(key);
            DGUIStructureValue* obj22 = obj->children->operator [](key);
            this->loadSubFolder(path, newLine,  obj22);
            line->AddChild(newLine);
        }
    }
}

SProjectExplorer::loadFolder(DGUIProject * dir){
    QMap<QString, DGUIStructureValue*>* obj = dir->getStructureAsTree();
    FoldLine *masterLine = new FoldLine();
    masterLine->SetText("scripts");
    QString workingPath = dir->dir;
    foreach(QString key, obj->keys()){
        if(key == "#childrenOfThisParentKappaKappaChameleon"){
            //foreach(QString key, )
            DGUIStructureValue *arr = obj->operator []("#childrenOfThisParentKappaKappaChameleon");
            //QList<QString>* arrRaw= arr->superChildList
            foreach(QString value, *(arr->superChildList)){
                FoldLine *newLine = new FoldLine();
                newLine->SetImage("page");
                newLine->SetText(value);
                masterLine->AddChild(newLine);
           }

        }else{
            FoldLine *newLine = new FoldLine();
            newLine->SetText(key);

            DGUIStructureValue* obj22 = obj->operator [](key);
            this->loadSubFolder(workingPath, newLine,  obj22);
            masterLine->AddChild(newLine);
        }
    }
    flow->addWidget(masterLine);
}


SProjectExplorer::y()
{
   // f = f + 1;
    //QFont fb( "Arial", f, QFont::Bold);
   // lbl->setFont( fb);
}


#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QTimer>
#include <QGridLayout>
#include <QJsonArray>

#include "ui/project_explorer/sprojectexplorer.h"
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

SProjectExplorer::loadSubFolder(QString path, FoldLine *line, QJsonObject* obj){
    QJsonObject obj2 = *obj;
    foreach(QString key, obj->keys()){
        if(key == "dirContainer"){
            QJsonArray arr = obj2["dirContainer"].toArray();
            foreach(QJsonValue value, arr){
                FoldLine *newLine = new FoldLine();
                newLine->SetImage("page");
                newLine->SetText(value.toString());
                line->AddChild(newLine);
            }
        }
    }
}

SProjectExplorer::loadFolder(DGUIProject * dir){
    QJsonObject obj = dir->getStructureAsJson();
    qDebug("ALRIGHT WE DONE GETTING THE JSON OF THE FOLDER");
    QString workingPath = dir->dir;
    qDebug("ALRIGHT WE LOADING THE FOLDER");
    foreach(QString key, obj.keys()){
        qDebug("ALRIGHT WE LOADING " + key.toLatin1());
        if(key == "dirContainer"){
            //foreach(QString key, )
        }else{
            FoldLine *newLine = new FoldLine();
            newLine->SetText(key);
            QJsonObject obj22 = obj[key].toObject();
            this->loadSubFolder(workingPath, newLine,  &obj22);
            qDebug("Appending widget main %d", newLine);
            flow->addWidget(newLine);
        }
    }
    qDebug("ALRIGHT WE DONE THE FOLDER");
}


SProjectExplorer::y()
{
   // f = f + 1;
    //QFont fb( "Arial", f, QFont::Bold);
   // lbl->setFont( fb);
}


#include "dguiproject.h"

#include <QtGui>
#include <QString>
#include <QJsonObject>
#include <QMap>
#include <QDirIterator>
#include <QDir>

#include "dguistructurevalue.h"

DGUIProject::DGUIProject(QString *dir, QString *name)
{
    qDebug("Initialize Project");
    QString actualName;
    if(!name){
        qDebug("Generate Name");
        actualName = dir->right(dir->size() - dir->lastIndexOf("/"));
    }else{
        actualName = *name;
    }
    this->dir = *dir;
    qDebug() << actualName;
    qDebug("1");
    QDirIterator it(*dir, QStringList() << "*.d2gui", QDir::Files, QDirIterator::Subdirectories);
    qDebug("2");
    while (it.hasNext()){
        QString nex = it.next();
        qDebug() << nex;
        files.append(new DGUIFile(&nex));
    }

    qDebug("Done Initialize Project");
    this->getStructureAsJson();
}

/*
 * warning - hefty operation
 * but returns a neatly packed c++ structure
 * Q.Q
 */
QMap<QString, DGUIStructureValue*>* getStructureAsTree()
{
    QMap<QString, DGUIStructureValue*>* fileStructure = new QMap<QString, DGUIStructureValue*>*;
    //DGUIStructureValue *ultimateChild = new DGUIStructureValue("#childrenOfThisParentKappaKappaChameleon");

    foreach(DGUIFile* f, files){
        QString dirNew = f->dir.right(f->dir.size() - this->dir.size() - 1);
        QMap<QString, DGUIStructureValue*> *proc = fileStructure;
        //DGUIStructureValue *procParent = ultimateChild;
        int i = 0;

        while((i = dirNew.indexOf("/")) != -1){
            QString subDir = dirNew.left(i);
            dirNew = dirNew.right(dirNew.size() - i - 1);
            i = dirNew.indexOf("/");

            if(!proc->contains(subDir)){
                proc->insert(dirNew, new DGUIStructureValue(dirNew));
            }

            //procParent = proc->operator [](dirNew);
            proc = proc->operator [](dirNew)->children;
        }
        DGUIStructureValue *child;
        if(!proc->contains("#childrenOfThisParentKappaKappaChameleon")){
            child = new DGUIStructureValue("#childrenOfThisParentKappaKappaChameleon");
            proc->insert("#childrenOfThisParentKappaKappaChameleon", child);
        }else{
            child = proc->operator []("#childrenOfThisParentKappaKappaChameleon");
        }

        if(child->superChildList){
            child->superChildList = new QList<QString*>();
        }
        child->superChildList->append(dirNew);
    }

    return fileStructure;
}

/*
 * rip- json objects are read only
 * LOL
QJsonObject DGUIProject::getStructureAsJson()
{
    //This just in- you cant modify nested JSON objects in QT. Stupid shit.

    QJsonObject obj;
    qDebug("get structure as json");

    QJsonObject objen = QJsonObject();
    QJsonObject innerObjen = QJsonObject();
    QJsonArray arr = QJsonArray();
    arr.append(QString("wtf"));
    innerObjen["hi"] = arr;
    objen["hi2"] = innerObjen;
    arr = objen["hi2"].toObject()["hi"].toArray();
    arr.removeFirst();
    arr.append(QString("GOOD!"));
    qDebug() << objen["hi2"].toObject()["hi"].toArray().first().toString();

    foreach(DGUIFile *f, files){

        QString dirNew = f->dir.right(f->dir.size() - this->dir.size() - 1);
        QJsonObject *proc = &obj;
        int i = dirNew.indexOf("/");
        QJsonObject *objectToBeAdded =new QJsonObject();
        while(i != -1){
            QString subDir = dirNew.left(i);
            dirNew = dirNew.right(dirNew.size() - i - 1);
            i = dirNew.indexOf("/");
            objectToBeAdded =new QJsonObject();
            if(i == -1){
                if(proc->contains(subDir)){
                    //This is where that "read only" crap with nested objects comes in
                    //I can't modify something so far down the stream
                    //So I'm just gonna completely rebuild the object every time
                    //Elegant? no
                    //who cares.

                    QJsonArray *arr;
                    QJsonObject sub = proc->operator [](subDir).toObject();

                    *arr = proc->operator [](subDir).toObject()["dirContainer"].toArray();
                    arr->append(dirNew);

                    sub["dirContainer"] = *arr;
                    proc->insert(subDir,sub);

                }else{
                    qDebug("Make new");
                    QJsonArray *arr = new QJsonArray();
                    arr->append(dirNew);
                    objectToBeAdded->insert("dirContainer", *arr);
                    proc->insert(subDir, *objectToBeAdded);
                }
            }else{
                if(!proc->contains(subDir)){
                    proc->insert(subDir, *objectToBeAdded);
                }else{
                    *objectToBeAdded = proc->operator [](subDir).toObject();
                }
            }
            proc = objectToBeAdded;
        }

    }
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();

    qDebug() << bytes;
    qDebug("Returning out of the print!");
    return obj;
}*/

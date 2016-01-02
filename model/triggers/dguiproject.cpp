#include "dguiproject.h"

#include <QtGui>
#include <QString>
#include <QJsonObject>
#include <QDirIterator>
#include <QDir>

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

QJsonObject DGUIProject::getStructureAsJson()
{
    QJsonObject obj;
    qDebug("get structure as json");

    QJsonObject objen = QJsonObject();
    QJsonArray arr = QJsonArray();
    arr.append(QString("wtf"));
    objen["hi"] = arr;
    arr = objen["hi"].toArray();
    arr.removeFirst();
    arr.append(QString("GOOD!"));
    qDebug() << arr.first().toString();

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
                    qDebug("Size Before: %d ",proc->operator [](subDir).toObject()["dirContainer"].toArray().size());
                    QJsonArray *arr;
                    *arr = proc->operator [](subDir).toObject()["dirContainer"].toArray();
                    arr->append(dirNew);
                    qDebug("Size of JS Array %d", arr->size());
                    qDebug("Address: %d", arr);
                    qDebug("Size After %d ", proc->operator [](subDir).toObject()["dirContainer"].toArray().size());

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
    return obj;
}

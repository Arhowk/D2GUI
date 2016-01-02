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
                QJsonArray *arr = new QJsonArray();
                arr->append(dirNew);
                objectToBeAdded->insert("dirContainer", *arr);
            }
            if(!proc->contains(subDir)){
                objectToBeAdded->insert(QString("hello"), QString("world"));
                proc->insert(subDir, *objectToBeAdded);
            }else{
                *objectToBeAdded = proc->operator [](subDir).toObject();
            }
            proc = objectToBeAdded;

            i = dirNew.indexOf("/");
        }

    }
    return obj;
}

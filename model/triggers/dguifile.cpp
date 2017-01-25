#include "model/triggers/dguifile.h"
#include "model/triggers/dguiline.h"
#include "dguikeydatabase.h"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

/*
 * Represents the contents of a trigger area
 * This doesn't parse any data but just acts as a gatherer and storer for it
 */

DGUIFile::DGUIFile()
{

}

QString DGUIFile::getFullPath(){
    return this->dir;
}
QString DGUIFile::getRelativePath(){
    return this->dir;
}
QString DGUIFile::getFileName(){
    return this->name;
}

DGUIFile::DGUIFile(QString * dirPath, QString * relPath)
{
    QString path;
    if(relPath){
        path = *dirPath+ *relPath;
    }else{
        path = *dirPath;
    }
    this->dir = path;
    int position = path.lastIndexOf('/');
    this->name = dir.right( dir.length() - position - 1);
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
    }else{
        QByteArray fileData = file.readAll();
        if(true){ //TODO: Remove debug "true" once binary files are done
            QJsonDocument argDoc(QJsonDocument::fromJson(fileData));
            const QJsonObject &argJson = argDoc.object();
            if(argJson.length() == 0){
                qWarning("JSON Error on file " + path.toLatin1());
            }else{
                this->note = argJson["Note"].toString();
            }
        }else{
            //load as binary
        }
    }
}

/*Parses a tree of data*/
QList<DGUILine*>* parseTree(QJsonValue *obj, int blockMode){
    QList<DGUILine*>* list = new QList<DGUILine*>();
    switch(blockMode){
    case 0:{ //event
        QJsonArray arr = obj->toArray();
        foreach(QJsonValue str, arr){
            DGUILine *prototype = DGUIKeyDatabase::getLine(0, str.toObject()["Key"].toInt());
            DGUILine *real = prototype->branch();
            char i = 0;
            foreach(QJsonValue strb, str.toObject()["Arguments"].toArray()){
                QString strbc = strb.toString();
                real->setArgument(i++, new DGUIArgument((unsigned char)-1, &strb));
            }
            list->append(real);
        }

        break;}
    case 1:{ //condicion
        //QJsonObject conditionData = DGUIKeyDatabase::triggerDatabase["Conditions"];
        break;}
    case 2:{ //action
        //QJsonObject actionData = DGUIKeyDatabase::triggerDatabase["Actions"];
        break;}
    }
    return list;
}

DGUIFile DGUIFile::CreateBetaFile()
{
    DGUIFile file(new QString("D:/Code/Qt/D2GUI/DOTA Project/content/d2guitest/scripts/vscripts/ontowerdeath.d2gui"));
    DGUILine * event1;
    DGUILine * event2;
    DGUILine * condition1;
    DGUILine * condition2;
    DGUILine * action1;
    DGUILine * action2;
    DGUILine * action3;

    DGUILine* protoEvt1 = DGUIKeyDatabase::getKeyWithIndex(0,0);
    event1 = protoEvt1->branch();
    event1->setArgument(0, new DGUIArgument(1, new QJsonValue("-1")));
    event1->setArgument(1, new DGUIArgument(0, new QJsonValue("-1")));
    event1->setArgument(2, new DGUIArgument(2, new QJsonValue("1")));
    qDebug("Beta done");
    return DGUIFile();
    //qDebug(event1->toPrintString());
}

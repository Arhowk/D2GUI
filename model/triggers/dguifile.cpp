#include "model/triggers/dguifile.h"
#include "model/triggers/dguiline.h"
#include "dguikeydatabase.h"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>


DGUIFile::DGUIFile()
{

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
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
    }else{
        QByteArray fileData = file.readAll();
        if(true){
            QJsonDocument argDoc(QJsonDocument::fromJson(fileData));
            const QJsonObject &argJson = argDoc.object();
            if(argJson.length() == 0){
                qWarning("JSON Error on file " + path.toLatin1());
            }
        }else{
            //load as binary
        }
    }
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
    event1->setArgument(0, new DGUIArgument(1, new QString("-1")));
    event1->setArgument(1, new DGUIArgument(0, new QString("-1")));
    event1->setArgument(2, new DGUIArgument(2, new QString("1")));
    qDebug("Beta done");
    return DGUIFile();
    //qDebug(event1->toPrintString());
}

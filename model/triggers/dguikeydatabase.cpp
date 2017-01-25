#include <Qt>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QCoreApplication>
#include <QJsonArray>

#include "dguikeydatabase.h"
#include "dguiline.h"
//key = trigger
//argument = argument

QJsonObject DGUIKeyDatabase::argumentDatabase = QJsonObject();
QJsonObject DGUIKeyDatabase::triggerDatabase = QJsonObject();
QString DGUIKeyDatabase::workingDir = QString();
std::vector< std::vector<DGUILine *> > DGUIKeyDatabase::flattenedKeyDatabase(3, std::vector<DGUILine *>());


/* Functions Part 2 */

/* Returns the DGUILine of the trigger with the specified KEY under the specified parent */

DGUILine* DGUIKeyDatabase::getLine(unsigned char type, unsigned int key )
{
    return (flattenedKeyDatabase[type][key])->branch();
    /*QJsonObject relevant = flattenedKeyDatabase[type].toObject()[key].toObject();//[key].toObject(); //TODO: Store the data in such a way that char lookup is O(n)


    QList<DGUIArgument*>* protoList = new QList<DGUIArgument*>();

    //search for all of the arg instances
    QString pattern = "\\{([a-zA-Z_]+)\\}";\
    QRegExp rx(pattern);

    Qt::CaseSensitivity cs = Qt::CaseInsensitive;
    rx.setCaseSensitivity(cs);

    if(!rx.isValid()){
        qWarning("Invalid regex");
    }else{
        QString procTxt = relevant["dat"].toArray()[sub].toObject()["text"].toString();
        QList<DGUIArgument*>* protoList = new QList<DGUIArgument*>();
        QStringList list;
        int pos = 0;

        while ((pos = rx.indexIn(procTxt, 0)) != -1) {
            QString proc = rx.cap(1);
            //list << proc;
            DGUIArgument *newArg = getArgumentWithName(proc);
            protoList->append(newArg);
            int invertedPos = procTxt.length() - pos;
            procTxt = procTxt.left(pos) + procTxt.right(invertedPos - proc.length() - 2);
        }


        DGUILine * line = new DGUILine(sub, true, new QList<DGUIArgument*>(), protoList);

        qDebug("Processed Successfully");
        return line;
    }*/
    //return 0;
}


/* Outdated Functions */

DGUILine* DGUIKeyDatabase::getKeyWithIndex(unsigned char type, unsigned char index)
{
    QJsonObject relevant = triggerDatabase["Events"].toObject()["DOTA"].toObject(); //TODO: Store the data in such a way that char lookup is O(n)


    QList<DGUIArgument*>* protoList = new QList<DGUIArgument*>();

    //search for all of the arg instances
    QString pattern = "\\{([a-zA-Z_]+)\\}";\
    QRegExp rx(pattern);

    Qt::CaseSensitivity cs = Qt::CaseInsensitive;
    rx.setCaseSensitivity(cs);

    if(!rx.isValid()){
        qWarning("Invalid regex");
    }else{
        QString procTxt = relevant["dat"].toArray()[0].toObject()["text"].toString();
        QList<DGUIArgument*>* protoList = new QList<DGUIArgument*>();
        QStringList list;
        int pos = 0;

        while ((pos = rx.indexIn(procTxt, 0)) != -1) {
            QString proc = rx.cap(1);
            //list << proc;
            DGUIArgument *newArg = getArgumentWithName(proc);
            protoList->append(newArg);

            int invertedPos = procTxt.length() - pos;
            procTxt = procTxt.left(pos) + procTxt.right(invertedPos - proc.length() - 2);
        }


        DGUILine * line = new DGUILine(index, true, 0, protoList);


        return line;
    }
}
/*
DGUILine* DGUIKeyDatabase::getLine(QString big, QString key, int sub)
{
    QJsonObject relevant = triggerDatabase[big].toObject()[key].toObject(); //TODO: Store the data in such a way that char lookup is O(n)


    QList<DGUIArgument*>* protoList = new QList<DGUIArgument*>();

    //search for all of the arg instances
    QString pattern = "\\{([a-zA-Z_]+)\\}";\
    QRegExp rx(pattern);

    Qt::CaseSensitivity cs = Qt::CaseInsensitive;
    rx.setCaseSensitivity(cs);

    if(!rx.isValid()){
        qWarning("Invalid regex");
    }else{
        QString procTxt = relevant["dat"].toArray()[sub].toObject()["text"].toString();
        QList<DGUIArgument*>* protoList = new QList<DGUIArgument*>();
        QStringList list;
        int pos = 0;

        while ((pos = rx.indexIn(procTxt, 0)) != -1) {
            QString proc = rx.cap(1);
            //list << proc;
            DGUIArgument *newArg = getArgumentWithName(proc);
            protoList->append(newArg);
            int invertedPos = procTxt.length() - pos;
            procTxt = procTxt.left(pos) + procTxt.right(invertedPos - proc.length() - 2);
        }


        DGUILine * line = new DGUILine(sub, true, new QList<DGUIArgument*>(), protoList);

        qDebug("Processed Successfully");
        return line;
    }
}*/
DGUIArgument* DGUIKeyDatabase::getArgumentWithIndex(unsigned char index)
{
    //todo
    return 0;
}

DGUIArgument* DGUIKeyDatabase::getArgumentWithName(QString name)
{
    foreach(QString key, argumentDatabase.keys()){
        if(key == name){
            QJsonObject obj = argumentDatabase[key].toObject();
            DGUIArgument *arg = new DGUIArgument(obj["key"].toInt(),new QJsonValue(""), 1);
            arg->setJson(obj);

            return arg;
        }
    }
}

QString* DGUIKeyDatabase::getArgumentNameWithIndex(unsigned char index, QString * data)
{
    //todo
    return 0;
}

/* Recursive function called to flatten the key database */
void DGUIKeyDatabase::init_flatten_recurse(int index, QJsonValue current)
{
    foreach(QJsonValue& val, current.toArray()){
       QJsonObject& obj = val.toObject();
       if(obj["dat"].isNull())
       {
           //It's an addable- add it to the flattened table


           /* Init all the proto-args */

           //search for all of the arg instances
           QList<DGUIArgument*>* protoList = new QList<DGUIArgument*>();
           QString pattern = "\\{([a-zA-Z_]+)\\}";
           QRegExp rx(pattern);

           Qt::CaseSensitivity cs = Qt::CaseInsensitive;
           rx.setCaseSensitivity(cs);

           if(!rx.isValid()){
               qWarning("Invalid regex");
           }else{
               QString procTxt = obj["text"].toString();
               QStringList list;
               int pos = 0;

               while ((pos = rx.indexIn(procTxt, 0)) != -1) {
                   QString proc = rx.cap(1);
                   //list << proc;
                   DGUIArgument *newArg = getArgumentWithName(proc);
                   protoList->append(newArg);
                   int invertedPos = procTxt.length() - pos;
                   procTxt = procTxt.left(pos) + procTxt.right(invertedPos - proc.length() - 2);
               }



           }
           /* Create the DGUILine proto-arg list*/
           DGUILine *newLine = new DGUILine(index, true, 0, protoList);
           newLine->setJsValue(obj);

           flattenedKeyDatabase[index].insert(flattenedKeyDatabase[index].begin() + obj["key"].toInt(), newLine);
       }else{
           //It's a tree structure- recurse
           init_flatten_recurse(index, obj["dat"]);
       }
    }
}

bool DGUIKeyDatabase::init()
{
   //Setup working dir

    QString dir = QCoreApplication::applicationDirPath();
    int indof = dir.lastIndexOf("/");
    int indof2 = dir.lastIndexOf("/", indof-1);
    workingDir = dir.left(indof2+1);

    QFile triggerFile(QString(workingDir.toLatin1() + "D2GUI/resources/triggerdatabase.js"));

    if (!triggerFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open trigger file.");
        return false;
    }

    QByteArray saveData = triggerFile.readAll();

    QJsonDocument triggerDoc(QJsonDocument::fromJson(saveData));

    const QJsonObject &json = triggerDoc.object();

    triggerFile.close();



    QFile argumentFile(QString(workingDir.toLatin1() + "D2GUI/resources/argumentdatabase.js")); //im sorry i know this is an absolute dir

    if (!argumentFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open argument file.");
        return false;
    }

    QByteArray argData = argumentFile.readAll();

    QJsonDocument argDoc(QJsonDocument::fromJson(argData));

    const QJsonObject &argJson = argDoc.object();

    qDebug("Trigger Size: %d", json.size());
    qDebug("Argument Size: %d", argJson.size());

    argumentFile.close();


    argumentDatabase = argJson;
    triggerDatabase = json;

    //Flatten the trigger database

    /* init the vector */

    /* start the recurse */
    init_flatten_recurse(0, triggerDatabase["Events"].toObject()["dat"]);
    init_flatten_recurse(1, triggerDatabase["Conditions"].toObject()["dat"]);
    init_flatten_recurse(2, triggerDatabase["Actions"].toObject()["dat"]);


    /*

    QFile saveFile(QStringLiteral("D:/Code/Qt/D2GUI/resources/triggerdatabase.js"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open write file.");
    }else{

        QJsonObject gameObject;
        gameObject["hi"] = "hello";
        QJsonDocument saveDoc(gameObject);
        saveFile.write(saveDoc.toJson());
        saveFile.close();

    }*/

    return true;
}

DGUIKeyDatabase::DGUIKeyDatabase()
{

}


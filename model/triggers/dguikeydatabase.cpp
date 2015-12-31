#include <Qt>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "dguikeydatabase.h"
#include "dguiline.h"
//key = trigger
//argument = argument

QJsonObject DGUIKeyDatabase::argumentDatabase = QJsonObject();
QJsonObject DGUIKeyDatabase::triggerDatabase = QJsonObject();

DGUILine DGUIKeyDatabase::getKeyWithIndex(unsigned char index)
{

}
DGUIArgument DGUIKeyDatabase::getArgumentWithIndex(unsigned char index)
{

}

QString* DGUIKeyDatabase::getArgumentNameWithIndex(unsigned char index, QString * data)
{

}


DGUIKeyDatabase::init()
{

    QFile triggerFile(QStringLiteral("D:/Code/Qt/D2GUI/resources/triggerdatabase.js")); //im sorry i know this is an absolute dir

    if (!triggerFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = triggerFile.readAll();
    qDebug("byte array: %d", saveData.size());

    QJsonDocument triggerDoc(QJsonDocument::fromJson(saveData));

    const QJsonObject &json = triggerDoc.object();

    qDebug("finished: %d", json.length());

    qDebug(json["Events"].toObject()["temp"].toString().toUtf8().constData());

    triggerFile.close();



    QFile argumentFile(QStringLiteral("D:/Code/Qt/D2GUI/resources/argumentdatabase.js")); //im sorry i know this is an absolute dir

    if (!argumentFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray argData = argumentFile.readAll();
    qDebug("byte array: %d", argData.size());

    QJsonDocument argDoc(QJsonDocument::fromJson(argData));

    const QJsonObject &argJson = argDoc.object();

    qDebug("finished: %d", argJson.length());
    argumentFile.close();


    argumentDatabase = argJson;
    triggerDatabase = json;

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


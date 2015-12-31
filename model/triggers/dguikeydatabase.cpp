#include <Qt>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "dguikeydatabase.h"
#include "dguiline.h"
//key = trigger
//argument = argument

DGUILine DGUIKeyDatabase::GetKeyWithIndex(unsigned char index)
{

}

DGUIKeyDatabase::init()
{

    QFile triggerDatabase(QStringLiteral("D:/Code/Qt/D2GUI/resources/triggerdatabase.js")); //im sorry i know this is an absolute dir

    if (!triggerDatabase.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QByteArray saveData = triggerDatabase.readAll();
    qDebug("byte array: %d", saveData.size());

    QJsonDocument triggerDoc(QJsonDocument::fromJson(saveData));

    const QJsonObject &json = triggerDoc.object();

    qDebug("finished: %d", json.length());

    qDebug(json["Events"].toObject()["temp"].toString().toUtf8().constData());

    triggerDatabase.close();
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


#include "dgobject.h"
#include <QString>
#include <QJsonObject>

/*
 * The structure of this class-
 *
 *  static methods:
 *   string toKV(QJsonObject)
 *    converts a QJsonObject to a KV object
 *
 *   QJsonObject toJson(string)
 *    converts a KV object into a QJsonObject
 *
 *  properties:
 *    name:Get{Set}Name() = string
 *    descriptions:Get{Set}Description(int) = vector<string>
 *
 *    rawData:Get{Set}Key(string) = hashmap
 *
 *  private methods:
 *    string convertPairToKV(string, string)
 *       - used for
 *
 *  default methods:
 *    QJsonObject toJson()
 *      - converts this DGObject into a KV String (excluding it's external references)
 *
 *    vector<DGObject*> getObjectReferences()
 *      - returns all of the objects created as a result of this object
 */

DGObject::DGObject()
{

}




void DGObject::SetName(QString name)
{
    this->name = name;
}

QString DGObject::GetName()
{
    return this->name;
}

/* This function is rather large so I'm pushing it down here. It's more of a util function but I don't know where to put it */


QString DGObject::toKV(QJsonObject obj)
{
    int expecting = 0;
    //QString exp_token_val = {"\"", "{", "["};
    //QString exp_token_key = {"\""};

    return "";
}

#ifndef DGOBJECT_H
#define DGOBJECT_H

#include <QString>
#include <QJsonObject>
class DGObject
{
public:
    DGObject();
    QString name;
    void SetName(QString);
    QString GetName();
    QString toKV(QJsonObject obj);
};

#endif // DGOBJECT_H

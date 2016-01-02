#ifndef DGUIPROJECT_H
#define DGUIPROJECT_H

#include <QString>
#include <QJsonObject>
#include "dguifile.h"
#include "dguistructurevalue.h"
class DGUIProject
{
public:
    DGUIProject(QString *dir, QString *name=0);
    QString name;
    QList<DGUIFile*> files;
    QString dir;
    QJsonObject getStructureAsJson();
    QMap<QString, DGUIStructureValue*>* getStructureAsTree();
};

#endif // DGUIPROJECT_H

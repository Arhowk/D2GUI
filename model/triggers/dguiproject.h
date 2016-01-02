#ifndef DGUIPROJECT_H
#define DGUIPROJECT_H

#include <QString>
#include <QJsonObject>
#include "dguifile.h"
class DGUIProject
{
public:
    DGUIProject(QString *dir, QString *name=0);
    QString name;
    QList<DGUIFile*> files;
    QString dir;
    QJsonObject getStructureAsJson();
};

#endif // DGUIPROJECT_H

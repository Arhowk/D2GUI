#ifndef DGUISTRUCTUREVALUE_H
#define DGUISTRUCTUREVALUE_H

#include <QMap>
#include <QString>
#include "dguifile.h"

class DGUIStructureValue
{
public:
    DGUIStructureValue(QString* name=0);
    DGUIStructureValue(char []);
    QString *name;
    bool isFile;
    QMap<QString, DGUIStructureValue*>* children;
    append(DGUIStructureValue*);
    QString child;
    QList<DGUIFile*>* superChildList;
};

#endif // DGUISTRUCTUREVALUE_H

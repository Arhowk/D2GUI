#include "dguistructurevalue.h"

DGUIStructureValue::DGUIStructureValue(QString *name)
{
    this->name = name;
    this->isFile = name->endsWith(QString(".d2gui"));
    superChildList = 0;
    children = new QMap<QString, DGUIStructureValue*>();
}

DGUIStructureValue::DGUIStructureValue(char  name[])
{
   this->name = new QString(name);
   this->isFile = this->name->endsWith(QString(".d2gui"));
    superChildList = 0;
    children = new QMap<QString, DGUIStructureValue*>();
}

DGUIStructureValue::append(DGUIStructureValue * val){
    if(isFile){
        qWarning("Attempted to append to a non-directory");
    }else{
        children->operator [](*(val->name)) = val;
    }
}

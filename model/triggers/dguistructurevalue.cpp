#include "dguistructurevalue.h"

DGUIStructureValue::DGUIStructureValue(QString *name)
{
    this->name = name;
    this->isFile = name->endsWith(QString(".d2gui"))
}

DGUIStructureValue::append(DGUIStructureValue * val){
    if(isFile){
        qWarning("Attempted to append to a non-directory");
    }else{

    }
}

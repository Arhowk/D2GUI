#include <QString>

#include "dguiline.h"
#include "model/triggers/dguiargument.h"
#include "dguikeydatabase.h"

DGUIArgument::DGUIArgument(unsigned char argType, QString * data, unsigned char pseudoArgType)
{
    this->argType = argType;
    dat = data;

    if(pseudoArgType){
        this->pseudoArgType = pseudoArgType;
    }else{
        this->pseudoArgType = argType;
    }
}

DGUIArgument::DGUIArgument(unsigned char argType, DGUILine * data, unsigned char pseudoArgType)
{
    this->argType = argType;
    isLine = true;
    lineReference = data;

    if(pseudoArgType){
        this->pseudoArgType = pseudoArgType;
    }else{
        this->pseudoArgType = argType;
    }
}

bool DGUIArgument::typeMatch(DGUIArgument *argb){
    return argb->argType == this->argType || argb->pseudoArgType == this->pseudoArgType;
}

QByteArray DGUIArgument::toPrintString(){
    return DGUIKeyDatabase::getArgumentNameWithIndex(argType, dat)->toLatin1();
}

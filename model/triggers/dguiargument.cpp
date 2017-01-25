#include <QString>
#include <QJsonObject>
#include <QDebug>
#include <QJsonValue>

#include "dguiline.h"
#include "model/triggers/dguiargument.h"
#include "dguikeydatabase.h"

/*
 * Just a storage type for an "argument"
 */

DGUIArgument::DGUIArgument(unsigned char argType, QJsonValue * data, unsigned char pseudoArgType)
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


void DGUIArgument::setJson(QJsonObject obj)
{
    this->obj = obj;
}

bool DGUIArgument::typeMatch(DGUIArgument *argb){
    return argb->argType == this->argType || argb->pseudoArgType == this->pseudoArgType;
}

QString DGUIArgument::toPrintString(){
    if(this->dat->isNull())
    {
        return this->obj["default_text"].toString();
    }else{
        QJsonObject obj = this->obj["dat"].toObject();

        foreach(QString val, obj.keys())
        {
            QJsonValue val2 = obj[val];
            if(val2.toInt() == dat->toInt())
            {
                return val;
            }
        }

        return this->obj["default_text"].toString();
    }
}

DGUIArgument* DGUIArgument::branch(QJsonValue * val)
{
   DGUIArgument *reg = new DGUIArgument(argType, val, pseudoArgType);
   reg->obj = obj;
   return reg;
}

#include <QList>

#include "dguiargument.h"
#include "model/triggers/dguiline.h"

DGUILine::DGUILine(unsigned char prototypeKey, bool isPrototype, QList<DGUIArgument*> *list, QList<DGUIArgument*> *prototypeList)
{
    this->isPrototype = isPrototype;
    this->prototypeKey = prototypeKey;
    this->argList = list;
    this->prototypeList = prototypeList;
}

DGUILine* DGUILine::branch()
{
    if(!isPrototype){
        qWarning("Attempted to branch off of a DGUILine that isnt a prototype");
    }else{
        DGUILine *newLine = new DGUILine(this->prototypeKey, false, new QList<DGUIArgument*>(), prototypeList);
        return newLine;
    }
}

DGUILine::setArgument(unsigned char index, DGUIArgument *arg)
{
    if(argList->at(index)){
        DGUIArgument *argb = argList->at(index);
        if(arg->typeMatch(argb)){

        }else{
            qWarning("Attempted to set an argument for a DGUILine with the wrong arg type");
        }
    }else if(argList->size() < index){

    }else{
        qWarning("Attempted to set an argument for a DGUILine beyond its argument count");
    }
}

QByteArray DGUILine::toPrintString()
{
    QByteArray orig = "";

    if(isPrototype){
        orig = "[Prototype] ";
    }

    return orig;

}

/*
DGUILine::AppendArgument(DGUIArgument *arg)
{
    if(!prototypeList && !prototypeLine){
        qWarning("Attempt to add an argument to a DGUILine with no prototype attached");
    }
}*/

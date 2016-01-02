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
        qDebug("Branching off of a good dguiline");
        DGUILine *newLine = new DGUILine(this->prototypeKey, false, new QList<DGUIArgument*>(), prototypeList);
        return newLine;
    }
}

DGUILine::setArgument(unsigned char index, DGUIArgument *arg)
{
    if(prototypeList->size() > index){
        DGUIArgument *argb = prototypeList->at(index);
        if(arg->typeMatch(argb)){
            qDebug("Arg Match!");
        }else{
            qWarning("Attempted to set an argument for a DGUILine with the wrong arg type");
            qWarning("%d %d", argb->argType, arg->argType);
        }
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

#include <QList>
#include <QDebug>

#include "dguiargument.h"
#include "model/triggers/dguiline.h"

/*
 * Developers notes:
 * What is a DGUILine prototype?
 * A DGUILine prototype holds the list of argument TYPES that a line should have
 * a non-prototype holds their actual values
 * use .branch() to create a dguiline from a prototype
 *
 * note ima try not to use this because u can just create a normal line with a prototype list and ignore this alltogeteher
 * its only really useful if u premake the prototypes than retrieve them upon request
 *
 */

DGUILine::DGUILine(unsigned char prototypeKey, bool isPrototype, QList<DGUIArgument*> *list, QList<DGUIArgument*> *prototypeList)
{
    this->isPrototype = isPrototype;
    this->prototypeKey = prototypeKey;
    this->argList = list;
    this->prototypeList = prototypeList;
}
/* Note- We made this its own function because i don't want to go back and fix everything */
void DGUILine::setJsValue(QJsonObject obj)
{
    this->obj = obj;

    //Finally we have the js obj- lets make the trigger string

    //First drag out the string
    this->triggerString = obj["text"].toString();

    //Drag out every argument
    //search for all of the arg instances
    QString pattern = "\\{([a-zA-Z_]+)\\}";\
    QRegExp rx(pattern);

    Qt::CaseSensitivity cs = Qt::CaseInsensitive;
    rx.setCaseSensitivity(cs);
    int currentArg = 0;
    qDebug() << "Set JS Value";

    if(!rx.isValid()){
        qWarning("Invalid regex");
    }else{
        QString procTxt = this->triggerString;
        int pos = 0;

        while ((pos = rx.indexIn(this->triggerString, 0)) != -1) {
            QString proc = rx.cap(1);
            int len = proc.length();
            //We have the cap and the pos- replace it with the arg value or the protoarg's default value
            qDebug() << "Proc:" << proc;
            qDebug() << "Proc:" << prototypeList;
            qDebug() << "Proc:" << prototypeList->at(currentArg);
            qDebug() << "Proc:" << prototypeList->at(currentArg)->obj;
            qDebug() << "Proc:" << proc;
            QString replace = "<a href='Hello' style='color: red;'>(" + prototypeList->at(currentArg)->obj["default_text"].toString() + ")</a>";

            int invertedPos = this->triggerString.length() - pos;
            this->triggerString = this->triggerString.left(pos) + replace + this->triggerString.right(invertedPos - proc.length() - 2);
            currentArg++;
        }
    }
    this->triggerString = "DOTA - " + this->triggerString;
}

DGUILine* DGUILine::branch()
{
    if(!isPrototype){
        qWarning("Attempted to branch off of a DGUILine that isnt a prototype");
    }else{
        qDebug("Branching off of a good dguiline");
    }
    DGUILine *newLine = new DGUILine(this->prototypeKey, false, new QList<DGUIArgument*>(), prototypeList);
    newLine->obj = obj;
    newLine->triggerString = triggerString;
    return newLine;
}

void DGUILine::setArgument(unsigned char index, DGUIArgument *arg)
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

QString DGUILine::toTriggerString()
{
    return this->triggerString;
}


QString DGUILine::getIcon()
{
    return "lightning";
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

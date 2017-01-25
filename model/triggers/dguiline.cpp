#include <QList>
#include <QDebug>
#include <vector>
#include <QJsonValue>

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

DGUILine::DGUILine(unsigned char prototypeKey, bool isPrototype, std::vector<DGUIArgument*> *list, QList<DGUIArgument*> *prototypeList)
{
    this->isPrototype = isPrototype;
    this->prototypeKey = prototypeKey;
    this->argList = list;
    if(!list || list->size() < prototypeList->size())
    {
        this->argList = new std::vector<DGUIArgument*>();
        foreach(DGUIArgument* arg, *prototypeList)
        {
             this->argList->push_back(arg->branch(new QJsonValue()));
        }
    }
    this->prototypeList = prototypeList;
}
/* Note- We made this its own function because i don't want to go back and fix everything */
void DGUILine::setJsValue(QJsonObject obj)
{
    this->obj = obj;

    //Finally we have the js obj- lets make the trigger string
    calculatePrintString();
}

void DGUILine::calculatePrintString()
{
    qDebug() << "Calculate PRint String";
    //First drag out the string
    this->triggerString = obj["text"].toString();

    //Drag out every argument
    //search for all of the arg instances
    QString pattern = "\\{([a-zA-Z_]+)\\}";\
    QRegExp rx(pattern);

    Qt::CaseSensitivity cs = Qt::CaseInsensitive;
    rx.setCaseSensitivity(cs);
    int currentArg = 0;
    if(!rx.isValid()){
        qWarning("Invalid regex");
    }else{
        QString procTxt = this->triggerString;
        int pos = 0;

        while ((pos = rx.indexIn(this->triggerString, 0)) != -1) {
            QString proc = rx.cap(1);
            int len = proc.length();
            //We have the cap and the pos- replace it with the arg value or the protoarg's default value
            QString replace = "<a href='Hello' ";
            if(!argList->at(currentArg)->dat->isNull())
            {
                replace = replace + ">(" + argList->at(currentArg)->toPrintString();
            }else{
                replace = replace + "style='color: red;'>(" + prototypeList->at(currentArg)->obj["default_text"].toString();
            }
            replace = replace + + ")</a>";

            int invertedPos = this->triggerString.length() - pos;
            this->triggerString = this->triggerString.left(pos) + replace + this->triggerString.right(invertedPos - proc.length() - 2);
            currentArg++;
        }
    }
    this->triggerString = "DOTA - " + this->triggerString;

    emit recalculatePrintString();
}

DGUILine* DGUILine::branch()
{
    if(!isPrototype){
        qWarning("Attempted to branch off of a DGUILine that isnt a prototype");
    }else{
        qDebug("Branching off of a good dguiline");
    }
    DGUILine *newLine = new DGUILine(this->prototypeKey, false, new std::vector<DGUIArgument*>(), prototypeList);
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

void DGUILine::setArgument(unsigned char index, QJsonValue *arg)
{
    //this->argList->append();
    this->argList->insert(this->argList->begin() + index, this->prototypeList->at(index)->branch(arg));
    qDebug() << "Set Arg";
    calculatePrintString();
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

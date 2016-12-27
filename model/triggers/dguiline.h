#ifndef DGUILINE_H
#define DGUILINE_H

#include <vector>

#include <QList>
#include <QByteArray>
#include <QJsonObject>
#include <vector>

#include "dguiargument.h"

class DGUILine
{
public:
    DGUILine(unsigned char prototypeKey, bool isPrototype = true, QList<DGUIArgument*>* list=0, QList<DGUIArgument*>* prototypeList=0);

    bool isPrototype;
    unsigned char prototypeKey;
    QList<DGUIArgument*>* argList;
    QList<DGUIArgument*>* prototypeList;
    DGUILine *prototypeLine;
    QList<DGUILine*>* childrenList;



    void appendArgument(DGUIArgument*);
    DGUILine* branch();
    void setArgument(unsigned char, DGUIArgument*);
    QByteArray toPrintString();
    QString toTriggerString();
    QString getIcon();
    void setJsValue(QJsonObject);
    QJsonObject obj;

    QString triggerString;
    std::vector<int> argPositions;
    std::vector<int> argLengths;


};

#endif // DGUILINE_H

#ifndef DGUILINE_H
#define DGUILINE_H

#include <QList>
#include <QByteArray>

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

    appendArgument(DGUIArgument*);
    DGUILine* branch();
    setArgument(unsigned char, DGUIArgument*);
    QByteArray toPrintString();
};

#endif // DGUILINE_H

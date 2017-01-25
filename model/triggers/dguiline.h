#ifndef DGUILINE_H
#define DGUILINE_H

#include <vector>

#include <QList>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonValue>
#include <vector>
#include <QObject>
#include "dguiargument.h"

class DGUILine : public QObject
{
    Q_OBJECT
public:
    DGUILine(unsigned char prototypeKey, bool isPrototype = true, std::vector<DGUIArgument*>* list=0, QList<DGUIArgument*>* prototypeList=0);

    bool isPrototype;
    unsigned char prototypeKey;
    std::vector<DGUIArgument*>* argList;
    QList<DGUIArgument*>* prototypeList;
    DGUILine *prototypeLine;
    QList<DGUILine*>* childrenList;



    void appendArgument(DGUIArgument*);
    void calculatePrintString();
    DGUILine* branch();
    void setArgument(unsigned char, DGUIArgument*);
    void setArgument(unsigned char, QJsonValue*);
    QByteArray toPrintString();
    QString toTriggerString();
    QString getIcon();
    void setJsValue(QJsonObject);
    QJsonObject obj;


    QString triggerString;
    std::vector<int> argPositions;
    std::vector<int> argLengths;

signals:
    void recalculatePrintString();

};

#endif // DGUILINE_H

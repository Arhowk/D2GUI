#ifndef DGUIARGUMENT_H
#define DGUIARGUMENT_H

#include <QString>
#include <QJsonObject>
#include <QJsonValue>

class DGUILine;

class DGUIArgument
{
public:
    DGUIArgument(unsigned char, QJsonValue*, unsigned char = 0);
    DGUIArgument(unsigned char, DGUILine*, unsigned char = 0);
    bool isPrototype;
    bool isLine;
    DGUILine *lineReference;
    QJsonValue *dat;
    unsigned char argType;
    unsigned char pseudoArgType;
    QJsonObject obj;

    bool typeMatch(DGUIArgument*);
    void setJson(QJsonObject);
    QString toPrintString();

    DGUIArgument* branch(QJsonValue*);

};

#endif // DGUIARGUMENT_H

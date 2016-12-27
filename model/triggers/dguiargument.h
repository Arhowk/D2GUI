#ifndef DGUIARGUMENT_H
#define DGUIARGUMENT_H

#include <QString>
#include <QJsonObject>

class DGUILine;

class DGUIArgument
{
public:
    DGUIArgument(unsigned char, QString*, unsigned char = 0);
    DGUIArgument(unsigned char, DGUILine*, unsigned char = 0);
    bool isPrototype;
    bool isLine;
    DGUILine *lineReference;
    QString *dat;
    unsigned char argType;
    unsigned char pseudoArgType;
    QJsonObject obj;

    bool typeMatch(DGUIArgument*);
    void setJson(QJsonObject);
    QByteArray toPrintString();

};

#endif // DGUIARGUMENT_H

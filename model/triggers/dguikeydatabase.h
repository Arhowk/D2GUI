#ifndef DGUIKEYDATABASE_H
#define DGUIKEYDATABASE_H

#include "dguiline.h"

#include <QJsonObject>

class DGUIKeyDatabase
{
public:
    DGUIKeyDatabase();
    static DGUILine* getKeyWithIndex(unsigned char, unsigned char);
    static DGUIArgument* getArgumentWithIndex(unsigned char);
    static DGUIArgument* getArgumentWithName(QString);
    static QString* getArgumentNameWithIndex(unsigned char, QString*);
    static DGUILine* getLine(QString,QString,int);
    static init();
    static QString workingDir;

    static QJsonObject triggerDatabase;
    static QJsonObject argumentDatabase;
};

#endif // DGUIKEYDATABASE_H

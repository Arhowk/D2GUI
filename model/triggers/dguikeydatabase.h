#ifndef DGUIKEYDATABASE_H
#define DGUIKEYDATABASE_H

#include "dguiline.h"

#include <QJsonObject>

class DGUIKeyDatabase
{
public:
    DGUIKeyDatabase();
    static DGUILine getKeyWithIndex(unsigned char);
    static DGUIArgument getArgumentWithIndex(unsigned char);
    static QString* getArgumentNameWithIndex(unsigned char, QString*);
    static init();

    static QJsonObject triggerDatabase;
    static QJsonObject argumentDatabase;
};

#endif // DGUIKEYDATABASE_H

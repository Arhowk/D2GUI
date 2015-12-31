#ifndef DGUIKEYDATABASE_H
#define DGUIKEYDATABASE_H

#include "dguiline.h"

#include <QJsonObject>

class DGUIKeyDatabase
{
public:
    DGUIKeyDatabase();
    static DGUILine GetKeyWithIndex(unsigned char);
    static DGUILine GetArgumentWithIndex(unsigned char);
    static init();

    static QJsonObject &triggerDatabase;
    static QJsonObject &argumentDatabase;
};

#endif // DGUIKEYDATABASE_H

#ifndef DGUIKEYDATABASE_H
#define DGUIKEYDATABASE_H

#include "dguiline.h"
#include <vector>
#include <QJsonObject>
#include <QJsonValue>

class DGUIKeyDatabase
{
public:
    DGUIKeyDatabase();
    static DGUILine* getKeyWithIndex(unsigned char, unsigned char);
    static DGUIArgument* getArgumentWithIndex(unsigned char);
    static DGUIArgument* getArgumentWithName(QString);
    static QString* getArgumentNameWithIndex(unsigned char, QString*);
    static DGUILine* getLine(unsigned char,unsigned int);
    static bool init();
    static QString workingDir;

    static void init_flatten_recurse(int, QJsonValue );
    static QJsonObject triggerDatabase;
    static QJsonObject argumentDatabase;
    static std::vector< std::vector<DGUILine *> > flattenedKeyDatabase;
};

#endif // DGUIKEYDATABASE_H

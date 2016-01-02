#include "dguiproject.h"

#include <QString>
DGUIProject::DGUIProject(QString *dir, QString *name)
{

    if(!name){
        QString nameb = dir->right(dir->size() - dir->lastIndexOf("/"));
    }
}


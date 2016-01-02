#include "dguiproject.h"

#include <QString>
DGUIProject::DGUIProject(QString dir, QString name)
{
    if(!name){
        name = dir.right(dir.size() - dir.lastIndexOf("/"));
    }
}


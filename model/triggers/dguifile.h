#ifndef DGUIFILE_H
#define DGUIFILE_H

#include <QString>
#include "dguiline.h"
class DGUIFile
{
public:
    DGUIFile(QString* ,QString*qt=0);
    static DGUIFile CreateBetaFile();

    QString getFullPath();
    QString getRelativePath();
    QString getFileName();

    QString dir;
    QString name;
    QString note;
    QList<DGUILine*> events;
    QList<DGUILine*> conditions;
    QList<DGUILine*> actions;

private:
    DGUIFile();

};

#endif // DGUIFILE_H

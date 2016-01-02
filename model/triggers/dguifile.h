#ifndef DGUIFILE_H
#define DGUIFILE_H

#include <QString>

class DGUIFile
{
public:
    DGUIFile(QString* ,QString*qt=0);
    static DGUIFile CreateBetaFile();

    QString note;
    QList<DGUILine*> events;
    QList<DGUILine*> conditions;
    QList<DGUILine*> actions;

private:
    DGUIFile();

};

#endif // DGUIFILE_H

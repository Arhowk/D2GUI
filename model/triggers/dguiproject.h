#ifndef DGUIPROJECT_H
#define DGUIPROJECT_H


class DGUIProject
{
public:
    DGUIProject(QString dir, QString name=0);
    QString name;
    QList<DGUIFile*> files;
};

#endif // DGUIPROJECT_H

#ifndef SPROJECTEXPLORER_H
#define SPROJECTEXPLORER_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QJsonObject>
#include <QSignalMapper>
#include <QScrollArea>

#include "model/triggers/dguistructurevalue.h"
#include "ui/layout_shared/foldline.h"
#include "model/triggers/dguiproject.h"
#include "ui/layout/flowlayout.h"

class SProjectExplorer : public QScrollArea
{
    Q_OBJECT
public:
    explicit SProjectExplorer(QWidget *parent = 0);
    FlowLayout * flow;
    QLabel * lbl;
    QWidget * child;
    QSignalMapper * signalMapper;  //Matches the FoldLine widgets with their respective paths.
    int f;

    QList<QLine*> files;

    void loadFolder(DGUIProject*);
    void loadFolder(QString*);
    void loadSubFolder(QString, FoldLine*, DGUIStructureValue*);
signals:
    void changeFile(QString);
public slots:
    void y();
    void onLoadFile(QString);
};

#endif // SPROJECTEXPLORER_H

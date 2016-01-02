#ifndef SPROJECTEXPLORER_H
#define SPROJECTEXPLORER_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QJsonObject>

#include "ui/layout_shared/foldline.h"
#include "model/triggers/dguiproject.h"
#include "ui/layout/flowlayout.h"

class SProjectExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit SProjectExplorer(QWidget *parent = 0);
    FlowLayout * flow;
    QLabel * lbl;
    int f;

    QList<QLine*> files;

    loadFolder(DGUIProject*);
    loadFolder(QString*);
    loadSubFolder(QString, FoldLine*, QJsonObject*);
signals:

public slots:
    y();
};

#endif // SPROJECTEXPLORER_H

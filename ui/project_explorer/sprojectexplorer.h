#ifndef SPROJECTEXPLORER_H
#define SPROJECTEXPLORER_H

#include <QWidget>
#include <QLabel>
#include "ui/layout/flowlayout.h"
class SProjectExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit SProjectExplorer(QWidget *parent = 0);
    FlowLayout * flow;
    QLabel * lbl;
    int f;
signals:

public slots:
    y();
};

#endif // SPROJECTEXPLORER_H

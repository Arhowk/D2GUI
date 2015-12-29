#ifndef SMAINLAYOUT_H
#define SMAINLAYOUT_H

#include <QGridLayout>
#include <QSplitter>
#include <QMainWindow>

#include "ui/project_explorer/sprojectexplorer.h"

class SMainLayout : public QSplitter
{
    Q_OBJECT
public:
    explicit SMainLayout(QWidget *parent = 0, QMainWindow * qmdr = 0);

    SProjectExplorer * projectExplorer;
    setupMenu(QMainWindow * qmdr);

signals:

public slots:
    y();
};

#endif // SMAINLAYOUT

#ifndef SBETALAYOUT_H
#define SBETALAYOUT_H

#include <QGridLayout>
#include "sprojectexplorer.h"
#include <QMainWindow>

class SBetaLayout : public QGridLayout
{
    Q_OBJECT
public:
    explicit SBetaLayout(QWidget *parent = 0, QMainWindow * qmdr = 0);

    SProjectExplorer * projectExplorer;
    setupMenu(QMainWindow * qmdr);

signals:

public slots:
    y();
};

#endif // SBETALAYOUT_H

#ifndef SARGUMENTSELECTOR_H
#define SARGUMENTSELECTOR_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include "model/triggers/dguiargument.h"

class SArgumentSelector
        : public QDialog
{
    Q_OBJECT

public:
    SArgumentSelector(QWidget *parent, DGUIArgument* replacingArg);
};

#endif // SARGUMENTSELECTOR_H

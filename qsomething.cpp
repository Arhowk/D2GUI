#include "qsomething.h"

QSomething::QSomething(QWidget *parent) : QWidget(parent)
{

    QLabel * qtext = new QLabel(this);
    qtext->setText("hi");
}


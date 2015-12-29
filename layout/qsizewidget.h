#ifndef QSIZEWIDGET_H
#define QSIZEWIDGET_H

#include <QWidget>
#include <QSize>

class QSizeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QSizeWidget(QWidget *parent = 0);
    QSize getSize();
signals:

public slots:
};

#endif // QSIZEWIDGET_H

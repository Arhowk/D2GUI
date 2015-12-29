
#ifndef QCLICKLABEL_H
#define QCLICKLABEL_H
#include <QLabel>
#include <QObject>
#include <QString>
#include <QWidget>
#include <QMouseEvent>

class QClickLabel : public QLabel
{
Q_OBJECT
public:
    explicit QClickLabel( const QString& text="", QWidget* parent=0 );
    ~QClickLabel();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};
#endif

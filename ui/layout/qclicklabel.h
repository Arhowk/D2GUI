
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
    explicit QClickLabel( const QString& text="", QWidget* parent=0, bool textHighlighting=false);
    ~QClickLabel();
    bool shouldHighlight;
    bool mousePressed;
    bool mouseWithin;
signals:
    void clicked();
protected:
    void mouseReleaseEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};
#endif

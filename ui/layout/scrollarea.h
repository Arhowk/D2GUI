#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QWidget>
#include <QTimer>

class ScrollArea : public QWidget
{
    Q_OBJECT
public:
    explicit ScrollArea(QWidget *parent = 0);

    void SetChild(QWidget * child);
    void Recalculate();
    void SetHorizontalScrollVisible(int visible);
    void SetVerticalScrollVisible(int visble);
    void ScrollTo(int x, int y);
    void beta();
    int prevChildWidth = -1;
    int prevChildHeight = -1;

    int prevFrameWidth = -1;
    int prevFrameHeight = -1;

    int scrollX = 0;
    int scrollY = 0;

    int horizontalVisible = 0;
    int verticalVisible = 0;

    QWidget * horizontalScrollBar;
    QWidget * verticalScrollBar;
    QWidget * child;

signals:

public slots:
    void TimerExpire();
};

#endif // SCROLLAREA_H

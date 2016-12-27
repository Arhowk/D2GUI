#include "ui/layout/scrollarea.h"

ScrollArea::ScrollArea(QWidget *parent) : QWidget(parent)
{


    //Prepare the timer
    QTimer * timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(TimerExpire()));
    timer->setSingleShot(false);
    timer->start(30); //time specified in ms
}

void ScrollArea::beta()
{

}

void ScrollArea::SetHorizontalScrollVisible(int visible)
{
    if(visible)
    {
        //horizontalScrollBar->show();
    }else{
      // horizontalScrollBar->hide();
      //  horizontalScrollBar->setVisible(false);
    }
}

void ScrollArea::SetVerticalScrollVisible(int visible)
{

}

void ScrollArea::ScrollTo(int x, int y)
{

}

void ScrollArea::Recalculate()
{

}

void ScrollArea::TimerExpire()
{
    if(!child){
        return;
    }
    int contentX = child->width();
    int contentY = child->height();
    int layoutX = this->width();
    int layoutY = this->height();

    if(contentX != prevChildWidth || contentY != prevChildHeight || layoutX != prevFrameWidth || layoutY != prevFrameHeight){
        this->Recalculate();
    }

    prevChildWidth = contentX;
    prevChildHeight = contentY;
    prevFrameWidth = layoutX;
    prevFrameHeight = layoutY;
}


void ScrollArea::SetChild(QWidget * child)
{
    this->child = child;
    //this->Recalculate();
}

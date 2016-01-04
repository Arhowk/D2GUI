#include "ui/layout/qclicklabel.h"
#include <QPalette>
QClickLabel::QClickLabel(const QString& text, QWidget* parent, bool textHighlighting)
    : QLabel(parent)
{
    this->shouldHighlight = textHighlighting;
    setText(text);
}

QClickLabel::~QClickLabel()
{
}

void QClickLabel::enterEvent(QEvent *event)
{
    mouseWithin = true;
    if(shouldHighlight){
        this->setStyleSheet("QLabel { background-color : rgba(203,229,255,255); }");
    }
}
void QClickLabel::leaveEvent(QEvent *event)
{
    mouseWithin = false;
    if(shouldHighlight){
        this->setStyleSheet("QLabel { background-color : rgba(255,0,0,0); }");
    }
}

void QClickLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(shouldHighlight){
        if(mouseWithin){
            this->setStyleSheet("QLabel { background-color : rgba(203,229,255,255); }");
        }else{
            this->setStyleSheet("QLabel { background-color : rgba(0,0,0,0); }");
        }
    }
    QLabel::mouseReleaseEvent(event);
}

void QClickLabel::mousePressEvent(QMouseEvent* event)
{
    if(shouldHighlight){
        this->setStyleSheet("QLabel { background-color : rgba(200,220,250,255); }");
    }
    QLabel::mousePressEvent(event);
    emit clicked();
}

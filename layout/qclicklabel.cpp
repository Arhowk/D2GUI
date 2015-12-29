#include "layout/qclicklabel.h"

QClickLabel::QClickLabel(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    setText(text);
}

QClickLabel::~QClickLabel()
{
}

void QClickLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

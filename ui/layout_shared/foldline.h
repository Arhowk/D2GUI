#ifndef FOLDLINE_H
#define FOLDLINE_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QImage>
#include "ui/layout/qclicklabel.h"
#include "ui/layout/flowlayout.h"

class FoldLine : public QFrame
{
    Q_OBJECT
public:
    explicit FoldLine(QWidget *parent = 0);
    FoldLine * children;
    FlowLayout * childrenBoxLayout;
    QWidget * childrenBox;
    QClickLabel * collapseOpen;
    QClickLabel * collapseClose;
    QClickLabel * imageIcon;
    QClickLabel * blank;
    QWidget * notificationImage;
    QClickLabel * textLabel;
    QString *icon;


    int childrenVisible = 1;
    SetChild(FoldLine * child);
    RemoveChild(FoldLine * child);
    AddChild(FoldLine * child, bool sorted = false);
    SetImage(QString dir);
    SetText(QString str);
    SetHasCollapse(bool hasCollapse);

    static QImage * collapseOpenImage;
    static QImage * collapseCloseImage;
    static int hasImagesInit;

signals:

public slots:
    OnLabelPressed();
    OnLabelClicked();
    OnLabelReleased();

    OnCollapseClicked();
    OnLineClicked();
    OnLinkClicked();
};


#endif // FOLDLINE_

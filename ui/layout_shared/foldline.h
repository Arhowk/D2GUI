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
    QWidget * notificationImage;
    QLabel * textLabel;


    int childrenVisible = 0;
    SetChild(FoldLine * child);
    RemoveChild(FoldLine * child);
    AddChild(FoldLine * child);
    SetImage(QString dir);
    SetText(QString str);

    static QImage * collapseOpenImage;
    static QImage * collapseCloseImage;
    static int hasImagesInit;

signals:

public slots:
    OnCollapseClicked();
    OnLineClicked();
    OnLinkClicked();
};


#endif // FOLDLINE_

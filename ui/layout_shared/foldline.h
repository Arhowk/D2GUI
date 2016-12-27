#ifndef FOLDLINE_H
#define FOLDLINE_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QImage>
#include <QVBoxLayout>
#include "ui/layout/qclicklabel.h"
#include "ui/layout/flowlayout.h"

class FoldLine : public QFrame
{
    Q_OBJECT
public:
    explicit FoldLine(QWidget *parent = 0);
    FoldLine * children;
    QVBoxLayout * childrenBoxLayout;
    QWidget * childrenBox;
    QClickLabel * collapseOpen;
    QClickLabel * collapseClose;
    QClickLabel * imageIcon;
    QClickLabel * blank;
    QWidget * notificationImage;
    QClickLabel * textLabel;
    QString *icon;
    QString text;


    int childrenVisible = 1;
    void SetChild(FoldLine * child);
    void RemoveChild(FoldLine * child);
    QString GetText();
    void AddChild(FoldLine * child, bool sorted = true);
    void SetImage(QString dir);
    void SetText(QString str);
    void SetHasCollapse(bool hasCollapse);

    static QImage * collapseOpenImage;
    static QImage * collapseCloseImage;
    static int hasImagesInit;

signals:
    void clicked();

public slots:
    void OnLabelPressed();
    void OnLabelClicked();
    void OnLabelReleased();

    void OnCollapseClicked();
    void OnLineClicked();
    void OnLinkClicked();
};


#endif // FOLDLINE_

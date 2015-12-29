#include "foldline.h"
#include <QString>
#include <QPixmap>
#include <QSize>
#include "layout/qclicklabel.h"
#include "layout/flowlayout.h"

int FoldLine::hasImagesInit = 0;
QImage * FoldLine::collapseCloseImage = new QImage();
QImage * FoldLine::collapseOpenImage = new QImage();

FoldLine::OnCollapseClicked()
{
    childrenVisible = 1-childrenVisible;

    if(childrenVisible == 1){
        childrenBox->show();
        collapseClose->show();
        collapseOpen->hide();
    }else{
        childrenBox->hide();
        collapseClose->hide();
        collapseOpen->show();
    }
}

FoldLine::OnLineClicked()
{

}

FoldLine::OnLinkClicked()
{

}

FoldLine::FoldLine(QWidget *parent) : QFrame(parent)
{
    if(hasImagesInit == 0){
        hasImagesInit = 1;
        collapseCloseImage->load("arrow-closed.png");
        collapseOpenImage->load("arrow-opened.png");
    }
    //Object Initialization

    //All
    QGridLayout * gridLayout = new QGridLayout(this);

    //Top
    QWidget * upperLine = new QWidget();
    QGridLayout * upperGridLayout = new QGridLayout(upperLine);
    collapseOpen = new QClickLabel();
    collapseClose = new QClickLabel();
    imageIcon = new QClickLabel();
    textLabel = new QLabel();

    //Bottom
    QLabel * label = new QLabel();
    childrenBox = new QWidget();
    childrenBoxLayout = new FlowLayout();

    //Usage
    //Top
    collapseOpen->setPixmap(QPixmap(":/closed.png"));
    collapseClose->setPixmap(QPixmap(":/opened.png"));
    imageIcon->setPixmap(QPixmap(":/folder.png"));


    connect(collapseOpen, SIGNAL(clicked()), this, SLOT(OnCollapseClicked()));
    connect(collapseClose, SIGNAL(clicked()), this, SLOT(OnCollapseClicked()));



    //Bottom
    childrenBox->setLayout(childrenBoxLayout);
    childrenBox->setVisible(false);

    //Connections
    //Top
    upperGridLayout->addWidget(textLabel,0,3,1, 1, Qt::AlignLeft);
    upperGridLayout->addWidget(collapseOpen,0,0);
    upperGridLayout->addWidget(collapseClose,0,0);
    upperGridLayout->addWidget(imageIcon,0,1);

    collapseClose->hide();
    collapseOpen->show();

    //Bottom

    //Rest

    gridLayout->addWidget(upperLine,0,0,1,2);
    gridLayout->addWidget(childrenBox,1,1,1,2);
    gridLayout->setColumnMinimumWidth(0, 15);

    //Debug
    //childrenBoxLayout->addWidget(label);
    label->setText("Hello World!");
    textLabel->setText("LOL WTF");
    upperGridLayout->setMargin(0);
    upperGridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setSpacing(0);
    childrenBoxLayout->setMargin(0);
    childrenBoxLayout->setSpacing(0);
    qDebug("height : %d", upperLine->sizeHint().height());
    qDebug("wtf : %d", textLabel->sizeHint().height());
    qDebug("wtf2 : %d", collapseOpen->sizeHint().height());
    qDebug("wtf2 : %d", collapseClose->sizeHint().height());
    qDebug("wtf3 : %d", upperGridLayout->sizeHint().height());
    qDebug("Align Left %d", Qt::AlignLeft);
    upperGridLayout->setAlignment(textLabel, Qt::AlignLeft);
    //gridLayout->setRowMaximumHeight(0, 20); // 20px for top row


}


FoldLine::AddChild(FoldLine * child)
{
    childrenBoxLayout->addWidget(child);
}

FoldLine::RemoveChild(FoldLine * child)
{

}

FoldLine::SetImage(QString * dir)
{

}

FoldLine::SetText(QString * qstr)
{
    textLabel->setText(*qstr);
}


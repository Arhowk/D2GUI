#include <QString>
#include <QPixmap>
#include <QSize>
#include <QVBoxLayout>
#include "ui/layout_shared/foldline.h"
#include "ui/layout/qclicklabel.h"
#include "ui/layout/flowlayout.h"

int FoldLine::hasImagesInit = 0;
QImage * FoldLine::collapseCloseImage = new QImage();
QImage * FoldLine::collapseOpenImage = new QImage();

FoldLine::OnCollapseClicked()
{
    this->setFocus();
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


FoldLine::OnLabelPressed()
{

}

FoldLine::OnLabelClicked()
{

}

FoldLine::OnLabelReleased()
{

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
    blank = new QClickLabel();
    imageIcon = new QClickLabel();
    textLabel = new QClickLabel("",0,true);

    //Bottom
    QLabel * label = new QLabel();
    childrenBox = new QWidget();
    childrenBoxLayout = new QVBoxLayout();

    //Usage
    //Top
    collapseOpen->setPixmap(QPixmap(":/images/closed.png"));
    collapseClose->setPixmap(QPixmap(":/images/opened.png"));
    blank->setPixmap(QPixmap(":/images/blank.png"));
    imageIcon->setPixmap(QPixmap(":/images/folder.png"));


    connect(collapseOpen, SIGNAL(clicked()), this, SLOT(OnCollapseClicked()));
    connect(collapseClose, SIGNAL(clicked()), this, SLOT(OnCollapseClicked()));



    //Bottom
    childrenBox->setLayout(childrenBoxLayout);

    //Connections
    //Top
    upperGridLayout->addWidget(textLabel,0,3,1, 1, Qt::AlignLeft);
    upperGridLayout->addWidget(collapseOpen,0,0);
    upperGridLayout->addWidget(collapseClose,0,0);
    upperGridLayout->addWidget(blank,0,0);
    upperGridLayout->addWidget(imageIcon,0,1);

    collapseClose->show();
    collapseOpen->hide();
    blank->hide();

    //Bottom

    //Rest

    gridLayout->addWidget(upperLine,0,0,1,2);

    //So spanning 9999 columns lags like crazy when you're nesting columns because you're performing a lookup on a potentially 10,000 wide grid.. GG
    gridLayout->addWidget(childrenBox,1,1,1,10); //TODO: Find a better solution than to make the children box span 500 columns...
    gridLayout->setColumnMinimumWidth(0, 19);
    gridLayout->setColumnMinimumWidth(3, 100);

    childrenBox->setVisible(true);

    //Debug
    //childrenBoxLayout->addWidget(label);
    label->setText("Hello World!");
    textLabel->setText("LOL WTF");
    upperGridLayout->setMargin(1);
    upperGridLayout->setSpacing(3);
    gridLayout->setMargin(0);
    gridLayout->setSpacing(0);
    childrenBoxLayout->setMargin(0);
    childrenBoxLayout->setSpacing(0);
    upperGridLayout->setAlignment(textLabel, Qt::AlignLeft);
    //gridLayout->setRowMaximumHeight(0, 20); // 20px for top row


}


FoldLine::AddChild(FoldLine * addingChild, bool sorted)
{
    if(sorted){ //TODO: Remove the "or true" debug
        if(childrenBoxLayout->count() == 0){
            childrenBoxLayout->addWidget(addingChild);
        }else{
            int lastFileIndex = -1;
            QString lastFile = 0;
            bool isFolder = addingChild->icon == 0;
            foreach(QObject *child, childrenBox->children()){
                FoldLine *foldChild = (FoldLine*) child;
                int index = childrenBoxLayout->indexOf(foldChild);
                bool isChildFolder = foldChild->icon == 0;
                if(index != -1){
                    //if its a folder, place it on the bottom of folders
                    if(isFolder == isChildFolder){
                        if(strcmp(addingChild->GetText().toLatin1(),foldChild->GetText().toLatin1()) < 0){
                            childrenBoxLayout->insertWidget(index, addingChild);
                            return 0;
                        }
                        if(lastFile  == 0 || strcmp(foldChild->GetText().toLatin1(), lastFile.toLatin1()) > 0){
                            lastFile = foldChild->GetText();
                            lastFileIndex = index;
                        }
                    }
                }
            }
            if(isFolder || lastFileIndex == -1){ //Place folders on the bottom of the foldersif theres nothing bigger than them. Place files on the botom.
                childrenBoxLayout->insertWidget(lastFileIndex+1,addingChild);
            }else{
                childrenBoxLayout->addWidget(addingChild);
            }

        }
    }else{
        childrenBoxLayout->addWidget(addingChild);
    }
}

QString FoldLine::GetText()
{
    return this->text;
}

FoldLine::RemoveChild(FoldLine * child)
{

}

FoldLine::SetImage(QString dir)
{
    this->icon = &dir;
    imageIcon->setPixmap(QPixmap(QString(":/images/") + (dir) + QString(".png")));
}

FoldLine::SetText(QString qstr)
{
    this->text = qstr;
    textLabel->setText(qstr);
}

FoldLine::SetHasCollapse(bool hasCollapse)
{
    if(hasCollapse){
        this->OnCollapseClicked();
        this->OnCollapseClicked();
        this->blank->hide();
    }else{
        this->collapseClose->hide();
        this->collapseOpen->hide();
        this->blank->show();
    }
}

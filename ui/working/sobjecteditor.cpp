#include "sobjecteditor.h"
#include "QVBoxLayout"
#include <QImage>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QScrollArea>
#include <QPixmap>
#include <QLabel>

SObjectEditor::SObjectEditor(QWidget *parent)
    : QScrollArea(parent)
{
    //Self initialization code
    this->setFrameShape(QFrame::NoFrame);

    QWidget *contents = new QWidget;
    mainLayout= new QVBoxLayout;
    //Initialize the headerbar- option to switch from list view to widget view

    //Initialize the header- icon, name, lore(s)
    //HBox - left side is the icon info, right side is the description information
    header = new QHBoxLayout();
    headerWidget = new QWidget;

    //Initialize the icon section (Icon, change icon button below it)
    iconSection = new QVBoxLayout();
    image = new QLabel("Hello World");
    changeImage = new QPushButton("Change Icon");
    iconSection->addWidget(image);
    iconSection->addWidget(changeImage);
    header->addItem(iconSection);

    //Initialize the desc section
    descSection = new QVBoxLayout();
    name = new QLineEdit();
    descSection->addWidget(name);
    header->addItem(descSection);
    headerWidget->setLayout(header);

    //List view-
    listView = new QVBoxLayout();

    //Widget view-
    QWidget *widgetViewContainer = new QWidget;
    widgetViewLayout = new QVBoxLayout();
    widgetViewContainer->setLayout(widgetViewLayout);

    //Initialize the style sheet
     //todo


    //Initialize the content area
    contents->setLayout(mainLayout);

    //Finalizing Code
    //mainLayout->addWidget(headerWidget);
    mainLayout->addWidget(widgetViewContainer);

    contents->setMaximumHeight(5000);
    contents->setLayout(mainLayout);
    this->setWidget(contents);

    //Debug code
    contents->setStyleSheet("background-color: none;");
    headerWidget->setStyleSheet("background-color: none;");


}


void SObjectEditor::showIcon(bool show){

}

void SObjectEditor::showChangeIconButton(bool show){

}

void SObjectEditor::showDescriptions(QString upperDescription, QString middleDescription, QString lowerDescription)
{

}

void SObjectEditor::appendSet(QString name, DGObjectDataSet *set)
{
    qDebug("Append Set");
   // widgetView->addWidget(new QLabel("LOL"));
}

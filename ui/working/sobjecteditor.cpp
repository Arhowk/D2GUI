#include "sobjecteditor.h"

#include "QVBoxLayout"

SObjectEditor::SObjectEditor()
{
    //Initialize the headerbar- option to switch from list view to widget view

    //List view-
    listView = new QVBoxLayout();
     //todo


    //Widget view-
    widgetView = new QVBoxLayout();
    //Initialize the style sheet
     //todo

    //Initialize the header- icon, name, lore(s)

    //Initialize the content area
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

}

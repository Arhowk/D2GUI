#include "dgobjectdataset.h"
#include <QPair>
#include <QString>
#include <QList>

DGObjectDataSet::DGObjectDataSet()
{

}

void DGObjectDataSet::addInt(QString key, QString staticText, int default_, int minBound, int maxBound)
{

}

//QPair in ListOfValues = <internal name, dictionary name>
void DGObjectDataSet::addFlagSet(QString key, QString dictionaryName, QList<QPair<QString, QString>> listOfValues, QList<bool> default_)
{

}

//QPair in ListOfValues = <internal name, dictionary name>
void DGObjectDataSet::addDropdown(QString key, QString dictionaryName, QList<QPair<QString, QString>> listOfValues, int default_ )
{

}
//QPair in listofProperties = <internal name, dictionary name>
void DGObjectDataSet::addPassiveProperties(QList<QPair<QString,QString>> listOfProperties)
{

}

void DGObjectDataSet::addCheckbox(QString key, QString dictionaryName, int default_)
{

}

void DGObjectDataSet::addCustom(QString key, QString dictionaryName, int default_)
{

}

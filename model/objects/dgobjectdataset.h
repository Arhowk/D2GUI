#ifndef DGOBJECTDATASET_H
#define DGOBJECTDATASET_H

#include <QPair>
#include <QString>
#include <QList>

class DGObjectDataSet
{
public:
    DGObjectDataSet();
    void DGObjectDataSet::addInt(QString key, QString staticText, int default_ = 0, int minBound = -1, int maxBound = -1);

    //QPair in ListOfValues = <internal name, dictionary name>
    void DGObjectDataSet::addFlagSet(QString key, QString dictionaryName, QList<QPair<QString, QString>> listOfValues, QList<bool> default_ = QList<bool>());

    //QPair in ListOfValues = <internal name, dictionary name>
    void DGObjectDataSet::addDropdown(QString key, QString dictionaryName, QList<QPair<QString, QString>> listOfValues, int default_ = 0);

    //QPair in listofProperties = <internal name, dictionary name>
    void DGObjectDataSet::addPassiveProperties(QList<QPair<QString,QString>> listOfProperties);

    void DGObjectDataSet::addCheckbox(QString key, QString dictionaryName, int default_ = 0);
    void DGObjectDataSet::addCustom(QString key, QString dictionaryName, int default_ = 0);
};

#endif // DGOBJECTDATASET_H

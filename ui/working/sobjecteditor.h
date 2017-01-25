#ifndef SOBJECTEDITOR_H
#define SOBJECTEDITOR_H
#include <QString>
#include "model/objects/dgobjectdataset.h"
#include <QVBoxLayout>

class SObjectEditor
{
public:
    SObjectEditor();

    QVBoxLayout *widgetView, listView;

    void showIcon(bool show = true);
    void showChangeIconButton(bool show = true);
    void showDescriptions(QString upperDescription, QString middleDescription="", QString lowerDescription="");
    void appendSet(QString name, DGObjectDataSet *set);

};

#endif // SOBJECTEDITOR_H

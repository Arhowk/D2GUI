#ifndef SITEMEDITOR_H
#define SITEMEDITOR_H

#include "sobjecteditor.h"
#include "model/objects/dgobjectdataset.h"

class SItemEditor : public SObjectEditor
{
public:
    SItemEditor();

    DGObjectDataSet* generateGeneral();
    DGObjectDataSet* generateShop();
    DGObjectDataSet* generateProperties();

};

#endif // SITEMEDITOR_H

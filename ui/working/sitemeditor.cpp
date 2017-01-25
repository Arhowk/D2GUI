#include "sitemeditor.h"
#include <QPair>
#include <QString>
#include <QList>
#include "model/objects/dgobjectdataset.h"
/*
 *
 *                     name
 *      [ icon ]       desc
 *                     lore
 * ------------------------------------------
 *
 * General
 *
 *
 * Passive Properties
 *
 *         [ Drop down with properties] [ Area for entering value ] [] <- button for expanding stackability/some other stuff
 *
 *    (types of properties)
 *          Damage
 *          Stats
 *          Life/mana + regens
 *          Armor
 *          Vamp
 *          CDR
 *          cast range
 *          xpm/gpm
 *
 * Shop Attributes
 *
 *      Cost
 *      Cooldown
 *
 * Charges
 *      Presets
 *         Clarity - stackable, castable, charges used on cast, expires
 *         Mango- nonstackable, castable, no charges but consumed on cast, expires
 *         Raindrops - nonstackable, noncastable, expires
 *         Tangoes - nonstackable, charges used on cast, expires
 *         Urn Of Shadows/Bottle - nonstackable, charges used on cast, doesn't expire
 *
 *  todo rest of it
 *
 *
 *  Data set-
 *
 */
SItemEditor::SItemEditor()
    : SObjectEditor()
{
    /* Header */
    showIcon();
    showChangeIconButton();
    showDescriptions("Description", "Lore");

    appendSet("General", generateGeneral());
    appendSet("Shop", generateShop());
    appendSet("Properties", generateProperties());
    // Data Sets
}

DGObjectDataSet* SItemEditor::generateGeneral()
{
    DGObjectDataSet* set = new DGObjectDataSet();

    //Add the items
    //Shareability - generate the dropdown
    QList<QPair<QString,QString>> shareability;
    shareability.append(QPair<QString,QString>("ITEM_NOT_SHAREABLE", "Not Shareable"));
    shareability.append(QPair<QString,QString>("ITEM_PARTIALLY_SHAREABLE", "Partially Shareable (others cannot sell or upgrade)"));
    shareability.append(QPair<QString,QString>("ITEM_FULLY_SHAREABLE", "Fully Shareable"));
    shareability.append(QPair<QString,QString>("ITEM_FULLY_SHAREABLE_STACKING", "Fully Shareable with Stacking"));

    set->addDropdown("ItemShareability", "Shareable", shareability, 0);

    return set;
}

DGObjectDataSet* SItemEditor::generateShop()
{
    DGObjectDataSet* set = new DGObjectDataSet();

    //Add the items
    set->addInt("ShopCost", "Gold Cost", 0);
    set->addInt("Sho", "Gold Cost", 0);

    return set;
}

DGObjectDataSet* SItemEditor::generateProperties()
{
    DGObjectDataSet* set = new DGObjectDataSet();

    QList< QPair<QString,QString> > passives;

    passives.append(QPair<QString,QString>("LifeSteal", "Life Steal"));
    passives.append(QPair<QString,QString>("Damage", "Damage"));

    set->addPassiveProperties(passives);

    return set;
}

//void SItemEditor::onSetObject(DGObject *obj)
//{
    //This runs after the corresponding data set values have all been changed
//}

//void SItemEditor::onChangeIcon()
//{

//}

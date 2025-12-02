//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _core_c
#define _core_c

#include "/lib/services/materials/armor.h"
#include "/lib/services/materials/components.h"
#include "/lib/services/materials/enchantments.h"
#include "/lib/services/materials/materials.h"
#include "/lib/services/materials/weapons.h"

protected mapping BlueprintObjects = ([]);
protected mapping MaterialsForClass = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask string *validCraftingBonuses()
{
    string *enchantments = m_indices(equipmentEnchantments);
    for(int i = 0; i < sizeof(enchantments); i++)
    {
        enchantments[i] = "crafting " + enchantments[i];
    }
    return enchantments + ({ "crafting value multiplier", "crafting encumberance reduction",
        "crafting weapon class", "crafting defense class", "crafting attack",
        "crafting weight reduction", "crafting armor class", "crafting duration",
        "crafting enchantment power", "crafting potency", "crafting enchantments",
		"crafting vehicle structure", "crafting vehicle protection", "crafting vehicle speed", 
        "crafting vehicle capacity", "crafting henchman bonus", "crafting vehicle attack", 
        "crafting vehicle damage", "crafting vehicle handling",
    });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int prerequisitesMet(object blueprintObj, object user)
{
    return blueprintObj->checkPrerequisites(user) &&
        blueprintObj->checkResearch(user);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int materialsAvailable(object blueprintObj, object user)
{
    return blueprintObj->checkAgregateMaterials(user);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string getDescriptionDetails(object blueprintObj)
{
    string colorConfiguration = this_player() ?
        this_player()->colorConfiguration() : "none";
    object configuration = getService("configuration");

    return blueprintObj->displayPrerequisites(colorConfiguration, configuration) +
        blueprintObj->displayNeededMaterials(colorConfiguration, configuration);
}

#endif

//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _armor_statistics_c
#define _armor_statistics_c

#include "/lib/dictionaries/materials/components/combat-properties.c"
#include "/lib/dictionaries/materials/components/enchantments.c"

/////////////////////////////////////////////////////////////////////////////
protected nomask int getDamageProtectionData(object armor, object initiator)
{
    int baseAC = armor->query("armor class") +
        getMaterialDefense(armor, "physical");

    if (initiator && (armor != initiator->itemBeingCrafted()))
    {
        baseAC += initiator->magicalDefenseBonus() +
            calculateServiceBonuses("DefenseBonus", initiator) +
            (initiator->constitutionBonus() / 2) +
            (initiator->strengthBonus() / 2);
    }
    return baseAC;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getDamageProtection(object armor, object initiator)
{
    int baseAC = getDamageProtectionData(armor, initiator);

    return detailsText(colorConfiguration(initiator), "Damage Protection",
        to_string(baseAC));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string applyArmorDetails(object armor, object initiator)
{
    string ret = getDamageProtection(armor, initiator);
    
    string resistances = applyResistances(armor, initiator);
    if (resistances)
    {
        ret -= "\n";
        ret += resistances;
    }
    return applyMaterialDetails(armor, colorConfiguration(initiator)) +
        ret + 
        getEncumberance(armor, initiator);
}

#endif

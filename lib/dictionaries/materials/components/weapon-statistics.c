//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _weapon_statistics_c
#define _weapon_statistics_c

#include "/lib/dictionaries/materials/components/combat-properties.c"
#include "/lib/dictionaries/materials/components/enchantments.c"

/////////////////////////////////////////////////////////////////////////////
private nomask string getWeaponAttackInformation(object weapon, object initiator)
{
    int baseAttack = getAttackData(weapon, initiator);

    return detailsText(colorConfiguration(initiator), "Attack",
        to_string(baseAttack), to_string(baseAttack + 100));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getWeaponDamageInformation(object weapon, object initiator)
{
    string ret = "";
    int baseDamage = getDamageData(weapon, initiator);

    float modifier = baseDamage / 8.0;
    ret = detailsText(colorConfiguration(initiator), "Damage",
        to_string(to_int(baseDamage - modifier)), 
        to_string(to_int(baseDamage + modifier)));

    string enchantments = applyEnchantments(weapon, initiator);
    if (enchantments)
    {
        ret -= "\n";
        ret += enchantments;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getWeaponDefenseInformation(object weapon, object initiator)
{
    int baseDefense = getWeaponDefenseData(weapon, initiator);

    float modifier = baseDefense / 8.0;
    return detailsText(colorConfiguration(initiator), "Defense",
        to_string(to_int(baseDefense - modifier)),
        to_string(to_int(baseDefense + modifier)));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string applyWeaponDetails(object weapon, object initiator)
{
    return applyMaterialDetails(weapon, colorConfiguration(initiator)) +
        getWeaponAttackInformation(weapon, initiator) +
        getWeaponDamageInformation(weapon, initiator) +
        getWeaponDefenseInformation(weapon, initiator) +
        getEncumberance(weapon, initiator);
}

#endif

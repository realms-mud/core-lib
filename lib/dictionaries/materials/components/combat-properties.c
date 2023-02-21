//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _combat_properties_c
#define _combat_properties_c

#include "/lib/dictionaries/materials/components/general-properties.c"

/////////////////////////////////////////////////////////////////////////////
public nomask string *hasExtraAttackTypes(object item)
{
    string *retVal = 0;

    if(isValidItem(item) && item->query("weapon type"))
    {
        string material = item->query("material");
        if(isValidMaterial(material) && member(materials[material], "attack"))
        {    
            string *listOfAttackTypes = m_indices(materials[material]["attack"]);
            
            if(member(listOfAttackTypes, "physical") > -1)
            {
                listOfAttackTypes -= ({ "physical" });
            }
            
            if (sizeof(listOfAttackTypes))
            {
                retVal = listOfAttackTypes;
            }
        }
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getMaterialDamageType(object weapon)
{
    string *ret;
    if (isValidItem(weapon))
    {
        string weaponType = weapon->query("blueprint");
        if (weapon->query("primary damage type"))
        {
            ret = ({ weapon->query("primary damage type") });
        }
        else if (isValidWeaponBlueprint(weaponType))
        {
            ret = ({ weaponBlueprints[weaponType]["damage type"] });
        }
        else
        {
            ret = ({ "physical" });
        }

        string material = weapon->query("material");
        if (isValidMaterial(material) && member(materials[material], "attack"))
        {
            string *materialDmgs = m_indices(materials[material]["attack"]);
            materialDmgs -= ({ "physical" });

            ret += materialDmgs;
        }
    }
    return ret + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialDamage(object item, string type)
{
    int retVal = 0;

    if(isValidItem(item))
    {
        string material = item->query("material");
        if(isValidMaterial(material))
        {
            if(member(materials[material], "attack") &&
               member(materials[material]["attack"], type))
            {
                retVal = materials[material]["attack"][type];
            }
        }
                  
        retVal += getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialDefense(object item, string type)
{
    int retVal = 0;
    if(isValidItem(item))
    {
        string material = item->query("material");
        if(isValidMaterial(material))
        {
            if(member(materials[material], "defense") &&
               member(materials[material]["defense"], type))
            {
                retVal = materials[material]["defense"][type];
            }
        }
                  
        retVal += getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialDefendAttack(object item)
{
    int retVal = 0;

    if(isValidItem(item))
    {
        retVal += getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialAttack(object item)
{
    int retVal = 0;

    if (isValidItem(item))
    {
        string material = item->query("material");
        if (isValidMaterial(material))
        {
            if (member(materials[material], "attack rating"))
            {
                retVal += materials[material]["attack rating"];
            }
        }

        retVal += getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int calculateServiceBonuses(string methodToCheck, object initiator)
{
    int ret = 0;

    string *servicesToCheck = ({ "races", "guilds", "research", "traits",
        "biological", "background" });

    foreach(string serviceToCheck in servicesToCheck)
    {
        if (initiator->has(serviceToCheck))
        {
            ret += call_other(initiator,
                sprintf("%sBonusTo", serviceToCheck), methodToCheck);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int getAttackData(object weapon, object initiator)
{
    int baseAttack = weapon->query("weapon attack") +
        getMaterialAttack(weapon);

    if (initiator && (weapon != initiator->itemBeingCrafted()))
    {
        baseAttack += initiator->magicalAttackBonus() +
            calculateServiceBonuses("AttackBonus", initiator) +
            (initiator->dexterityBonus() / 2) +
            (initiator->intelligenceBonus() / 2);

        string skillToUse = weapon->query("weapon type");

        if (skillToUse && stringp(skillToUse))
        {
            baseAttack += call_other(initiator, "getSkillModifier",
                skillToUse);
        }
        baseAttack -= weapon->query("skill penalty");
    }
    return baseAttack;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int getDamageData(object weapon, object initiator)
{
    int baseDamage = weapon->query("weapon class") +
        getMaterialDamage(weapon, "physical");

    if (initiator && (weapon != initiator->itemBeingCrafted()))
    {
        baseDamage += initiator->magicalDamageBonus() +
            calculateServiceBonuses("DamageBonus", initiator) +
            (initiator->strengthBonus() / 2) +
            (initiator->wisdomBonus() / 4) +
            (initiator->intelligenceBonus() / 4);

        string skillToUse = weapon->query("weapon type");
        if (skillToUse && stringp(skillToUse))
        {
            baseDamage += call_other(initiator, "getSkillModifier",
                skillToUse) / 2;
        }
        baseDamage -= weapon->query("skill penalty");
    }
    return baseDamage;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int getWeaponDefenseData(object weapon, object initiator)
{
    int baseDefense = weapon->query("defense class") +
        getMaterialDefendAttack(weapon);

    if (initiator && (weapon != initiator->itemBeingCrafted()))
    {
        baseDefense += initiator->magicalDefendAttackBonus() +
            calculateServiceBonuses("DefendAttackBonus", initiator) +
            (initiator->dexterityBonus() / 2) +
            (initiator->wisdomBonus() / 2);

        string skillToUse = weapon->query("weapon type");
        if (skillToUse && stringp(skillToUse))
        {
            baseDefense += call_other(initiator, "getSkillModifier",
                skillToUse) / 2;
        }
        baseDefense -= weapon->query("skill penalty");
    }
    return baseDefense;
}

#endif

//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _blueprints_c
#define _blueprints_c

#include "/lib/dictionaries/materials/components/core.c"

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidWeaponBlueprint(string type)
{
    return (weaponBlueprints && mappingp(weaponBlueprints) &&
            member(weaponBlueprints, type) &&
            member(weaponBlueprints[type], "skill to craft") &&
            member(weaponBlueprints[type], "type") &&
            member(weaponBlueprints[type], "default encumberance"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidArmorBlueprint(string type)
{
    return (armorBlueprints && mappingp(armorBlueprints) &&
        member(armorBlueprints, type) &&
        member(armorBlueprints[type], "skill to craft") &&
        member(armorBlueprints[type], "type") &&
        member(armorBlueprints[type], "default encumberance"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidInstrumentBlueprint(string type)
{
    return ((instrumentBlueprints && mappingp(instrumentBlueprints) &&
        member(instrumentBlueprints, type) &&
        member(instrumentBlueprints[type], "skill to craft") &&
        member(instrumentBlueprints[type], "type") &&
        member(instrumentBlueprints[type], "default encumberance")) ||
        (member(({ "instrument: plucked", "instrument: bowed",
                "instrument: woodwind", "instrument: brass",
                "instrument: percussion" }), type) > -1));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidFoodBlueprint(string type)
{
    return (food && mappingp(food) && member(food, type) &&
        member(food[type], "crafting prerequisites") && 
        member(food[type], "type"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidDrinkBlueprint(string type)
{
    return (drinks && mappingp(drinks) && member(drinks, type) &&
        member(drinks[type], "crafting prerequisites") && 
        member(drinks[type], "type") &&
        member(drinks[type], "crafting materials"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidPotionBlueprint(string type)
{
    return (potions && mappingp(potions) && member(potions, type) &&
        member(potions[type], "crafting prerequisites") &&
        member(potions[type], "type") &&
        member(potions[type], "effects") &&
        member(potions[type], "crafting materials"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidArmorType(string type)
{
    return (member(validArmorTypes, type) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidWeaponType(string type)
{
    return (member(validWeaponTypes, type) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidDamageType(string type)
{
    return (member(validDamageTypes, type) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidBonus(string bonus)
{
    return (member(validBonuses, bonus) > -1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mixed getBlueprintData(object item, string type)
{
    mixed ret = 0;
    string itemType = item->query("blueprint");
    if (isValidWeaponBlueprint(itemType) && 
        member(weaponBlueprints[itemType], type))
    {
        ret = weaponBlueprints[itemType][type];
    }
    else if (isValidArmorBlueprint(itemType) &&
        member(armorBlueprints[itemType], type))
    {
        ret = armorBlueprints[itemType][type];
    }
    else if (isValidMaterial(itemType) &&
        member(materials[itemType], type))
    {
        ret = materials[itemType][type];
    }
    else if (isValidInstrumentBlueprint(itemType) &&
        member(instrumentBlueprints[itemType], type))
    {
        ret = instrumentBlueprints[itemType][type];
    }
    else if (isValidPotionBlueprint(itemType) &&
        member(potions[itemType], type))
    {
        ret = potions[itemType][type];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getBlueprintModifier(object item, string type)
{
    return to_int(getBlueprintData(item, type));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBlueprintDetails(object item, string type)
{
    string detail = getBlueprintData(item, type);
    return (detail && stringp(detail)) ? detail : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canCraftBlueprintWithMaterial(object initiator, 
                                                string blueprint,
                                                string material)
{
    int ret = 0;

    if (initiator && member(materials, material))
    {
        ret = 1;
        int skillLevel;

        if (member(weaponBlueprints, blueprint))
        {
            if (member(({ "bow", "crossbow" }), weaponBlueprints[blueprint]["type"]) > -1)
            {
                skillLevel = initiator->getSkill("bowyer and fletcher");
            }
            else
            {
                skillLevel = initiator->getSkill("weapon smithing");
            }
            ret &&= skillLevel >= weaponBlueprints[blueprint]["skill to craft"];
        }
        else if (member(armorBlueprints, blueprint))
        {
            ret &&= initiator->getSkill("armorer") >=
                armorBlueprints[blueprint]["skill to craft"];
        }

        switch(materials[material]["class"])
        {
            case "wood":
            {
                skillLevel = initiator->getSkill("wood crafting");
                break;
            }
            case "stone":
            {
                skillLevel = initiator->getSkill("stonemasonry");
                break;
            }
            case "crystal":
            {
                skillLevel = initiator->getSkill("gem crafting");
                break;
            }
            case "metal":
            {
                skillLevel = initiator->getSkill("metal crafting");
                break;
            }
            case "leather":
            {
                skillLevel = initiator->getSkill("leatherworking");
                break;
            }
            case "textile":
            {
                skillLevel = initiator->getSkill("sewing");
                break;
            }
            case "exotic":
            {
                skillLevel = initiator->getSkill("spellcraft");
                break;
            }
        }
        ret &&= skillLevel >= materials[material]["crafting skill required"];
    }
    return ret;
}

#endif

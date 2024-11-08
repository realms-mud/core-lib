//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _general_properties_c
#define _general_properties_c

#include "/lib/dictionaries/materials/components/blueprints.c"

/////////////////////////////////////////////////////////////////////////////
public nomask string getMaterialTypeForMaterial(string material)
{
    string type = 0;

    if(isValidMaterial(material) && 
        isValidMaterialType(materials[material]["class"]))
    {
        type = materials[material]["class"];
    }
    return type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialCraftsmanshipBonus(object item)
{
    int retVal = 0;
    
    if(isValidItem(item))
    {
        retVal = item->query("craftsmanship");
        
        string material = item->query("material");
        if(isValidMaterial(material))
        {
            retVal -= materials[material]["crafting skill required"];
        }
        
        retVal -= getBlueprintModifier(item, "skill to craft");
    }

    return (retVal > 0) ? retVal / 5 : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getRandomCraftsmanshipBonus(object item)
{
    int ret = 5 + random(15);

    string itemBlueprint = item->query("blueprint");
    if (member(weaponBlueprints, itemBlueprint))
    {
        ret += weaponBlueprints[itemBlueprint]["skill to craft"];
    }
    else if (member(armorBlueprints, itemBlueprint))
    {
        ret += armorBlueprints[itemBlueprint]["skill to craft"];
    }

    if (!random(5))
    {
        ret += 20 + random(25);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getDefaultValue(object item)
{
    int ret = getBlueprintModifier(item, "default value");

    string material = item->query("material");
 
    if (member(materials, material) && member(materials[material],
        "value multiplier"))
    {
        ret = to_int(ret * materials[material]["value multiplier"]);
    }
    return to_int(ret + (defaultValues[item->query("type")] * 
        (1 + 0.35 * (getMaterialCraftsmanshipBonus(item))) *
        (1 + 10 * item->query("enchanted"))));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialEncumberance(object item)
{
    int retVal = 0;
    
    if(isValidItem(item))
    {
        string material = item->query("material");
        retVal -= getMaterialCraftsmanshipBonus(item);
        retVal = (retVal > 0) ? retVal : 0;

        if(isValidMaterial(material))
        {
            if(member(materials[material], "encumberance"))
            {
                retVal = materials[material]["encumberance"];
            }
        }
    }

    return  retVal;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int getEncumberanceData(object item, object initiator)
{
    int encumberance = item->query("encumberance") +
        getMaterialEncumberance(item);

    if (initiator && (item != initiator->itemBeingCrafted()))
    {
        string skillToUse = item->query("weapon type") ||
            item->query("armor type");
        if (skillToUse && stringp(skillToUse))
        {
            encumberance -= call_other(initiator, "getSkillModifier",
                skillToUse);
        }
        encumberance += item->query("skill penalty");
    }
    return encumberance;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string applyMaterialDetails(object item, string colorConfiguration)
{
    string ret = "";
    string material = item->query("material");
    if (material)
    {
        ret += detailsText(colorConfiguration, "Material",
            capitalize(material));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getEncumberance(object item, object initiator)
{
    int encumberance = getEncumberanceData(item, initiator);

    return detailsText(colorConfiguration(initiator), "Encumberance",
        to_string(encumberance));
}

#endif

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _item_statistics_c
#define _item_statistics_c

#include "/lib/dictionaries/materials/components/armor-statistics.c"
#include "/lib/dictionaries/materials/components/weapon-statistics.c"

/////////////////////////////////////////////////////////////////////////////
protected nomask string applyBonusDetails(object item, object initiator)
{
    string ret = "";
    string *bonuses = sort_array(item->query("bonuses"),
                                (: return $1 > $2; :));

    if (sizeof(bonuses))
    {
        string colorConfiguration = colorConfiguration(initiator);

        foreach(string bonus in bonuses)
        {
            ret += configuration->decorate(sprintf("    %s: %d\n",
                capitalize(bonus), item->query(bonus)), "value", "equipment",
                colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getMaterialDetails(object item)
{
    string retVal = "";

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string getMaterialQualityFormatter(object equipment)
{
    string qualityFormat = "normal quality";
    string qualityMessage = "   ";

    if (getMaterialCraftsmanshipBonus(equipment) > 4)
    {
        qualityFormat = "masterwork";
        qualityMessage = "(M)";
    }
    else if (equipment->query("enchanted") > 4)
    {
        qualityFormat = "powerful enchantment";
        qualityMessage = "(P)";
    }
    else if (getMaterialCraftsmanshipBonus(equipment))
    {
        qualityFormat = "well-crafted";
        qualityMessage = "(C)";
    }
    else if (equipment->query("enchanted"))
    {
        qualityFormat = "enchanted";
        qualityMessage = "(E)";
    }

    return sprintf("%s %s", "%s", qualityMessage);
}

/////////////////////////////////////////////////////////////////////////////
public varargs string applyMaterialQualityToText(object equipment, 
    string text, object initiator)
{
    string qualityFormat = "normal quality";
    string qualityText = "typical for its type";

    if (getMaterialCraftsmanshipBonus(equipment) > 4)
    {
        qualityFormat = "masterwork";
        if(!text)
        {
            qualityText = "a masterwork item";
        }
    }
    else if (equipment->query("enchanted") > 4)
    {
        qualityFormat = "powerful enchantment";
        if (!text)
        {
            qualityText = "enchanted with a powerful aura";
        }
    }
    else if (equipment->query("enchanted"))
    {
        qualityFormat = "enchanted";
        if (!text)
        {
            qualityText = "enchanted";
        }
    }
    else if (getMaterialCraftsmanshipBonus(equipment))
    {
        qualityFormat = "well-crafted";
        if (!text)
        {
            qualityText = "a well-crafted item";
        }
    }
    else
    {
        equipment->identify();
    }

    if(!text)
    {
        text = sprintf("This %s is %s.\n", 
            equipment->query("blueprint") || "item",
            qualityText);
    }
    return configuration->decorate(text, qualityFormat, "equipment",
        colorConfiguration(initiator));
}

/////////////////////////////////////////////////////////////////////////////
private nomask string applyNonEquipmentDetails(object item, object initiator)
{
    string colorConfiguration = colorConfiguration(initiator);

    string ret = applyMaterialDetails(item, colorConfiguration);

    string enchantments = applyEnchantments(item, initiator);
    if (enchantments)
    {
        ret += configuration->decorate("    Enchantments: ", "value",
            "equipment", colorConfiguration) + enchantments;
    }
    string resistances = applyResistances(item, initiator);
    if (resistances)
    {
        ret += configuration->decorate("    Resistances: ", "value",
            "equipment", colorConfiguration) + resistances;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private int spellcraftCanIdentifyItem(object item, object initiator)
{
    return item && initiator && ((item->query("enchanted") * 5) <=
        (initiator->getSkillModifier("spellcraft")));
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string getEquipmentStatistics(object equipment, object initiator)
{
    string ret = applyMaterialQualityToText(equipment, 0, initiator);

    int canCraft = canCraftBlueprintWithMaterial(initiator,
        equipment->query("blueprint"), equipment->query("material"));

    int spellcraftCanIdentify = 
        spellcraftCanIdentifyItem(equipment, initiator);

    if (spellcraftCanIdentify && canCraft)
    {
        equipment->identify();
    }

    if(equipment->query("identified") || canCraft)
    {
        if (equipment->query("weapon type"))
        {
            ret += applyWeaponDetails(equipment, initiator);
        }
        else if (equipment->query("armor type"))
        {
            ret += applyArmorDetails(equipment, initiator);
        }
        else
        {
            ret += applyNonEquipmentDetails(equipment, initiator);
        }
    }

    if (equipment->query("identified") || spellcraftCanIdentify)
    {
        ret += applyBonusDetails(equipment, initiator);
    }

    if (equipment->query("weight"))
    {
        ret += detailsText(colorConfiguration(initiator),
            "Weight", to_string(equipment->query("weight")));
    }

    if (equipment->query("identified") && equipment->query("cursed"))
    {
        ret += configuration->decorate("This item is cursed!\n",
            "cursed", "equipment", colorConfiguration(initiator));
    }

    if (!equipment->query("identified"))
    {
        ret += configuration->decorate("This item has not been identified.\n",
            "unidentified", "equipment", colorConfiguration(initiator)); 
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getItemSummary(object equipment)
{
    mapping ret = ([
        "identified": equipment->query("identified")
    ]);

    if (equipment->query("weapon type"))
    {
        ret["Attack"] = getAttackData(equipment, 0);
        ret["Damage"] = getDamageData(equipment, 0);
        ret["Defense"] = getWeaponDefenseData(equipment, 0);
    }
    else if (equipment->query("armor type"))
    {
        ret["Soak"] = getDamageProtectionData(equipment, 0);
        ret["Encumberance"] = getEncumberanceData(equipment, 0);
    }
    else
    {
        ret["No data"] = 0;
    }

    return ret;
}

#endif

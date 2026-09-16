//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _item_statistics_c
#define _item_statistics_c

#include "/lib/services/materials/components/armor-statistics.c"
#include "/lib/services/materials/components/weapon-statistics.c"

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
protected nomask mapping getBonusMapping(object item)
{
    mapping ret = ([]);
    string *bonuses = sort_array(item->query("bonuses"),
                                (: return $1 > $2; :));

    foreach(string bonus in bonuses)
    {
        ret[bonus] = item->query(bonus);
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
private nomask string qualityTier(object equipment)
{
    string quality = "normal quality";

    if (getMaterialCraftsmanshipBonus(equipment) > 4)
    {
        quality = "masterwork";
    }
    else if (equipment->query("enchanted") > 4)
    {
        quality = "powerful enchantment";
    }
    else if (getMaterialCraftsmanshipBonus(equipment))
    {
        quality = "well-crafted";
    }
    else if (equipment->query("enchanted"))
    {
        quality = "enchanted";
    }
    return quality;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string getMaterialQualityFormatter(object equipment)
{
    mapping qualityMessages = ([
        "normal quality": "   ",
        "masterwork": "(M)",
        "powerful enchantment": "(P)",
        "well-crafted": "(C)",
        "enchanted": "(E)"
    ]);

    string qualityFormat = qualityTier(equipment);
    string qualityMessage = qualityMessages[qualityFormat];

    return sprintf("%s %s", "%s", qualityMessage);
}

/////////////////////////////////////////////////////////////////////////////
public varargs string applyMaterialQualityToText(object equipment, 
    string text, object initiator)
{
    mapping qualityTexts = ([
        "masterwork": "a masterwork item",
        "powerful enchantment": "enchanted with a powerful aura",
        "enchanted": "enchanted",
        "well-crafted": "a well-crafted item",
        "normal quality": "typical for its type"
    ]);

    string qualityFormat = qualityTier(equipment);
    string qualityText = qualityTexts[qualityFormat];

    if (qualityFormat == "normal quality")
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

    if ((equipment->query("identified") || canCraft) &&
        equipment->query("runes fused") > 0)
    {
        mapping fusedRunes = equipment->query("fused runes");
        string *runeNames = m_indices(fusedRunes);
        string colorConfig = colorConfiguration(initiator);
        ret += detailsText(colorConfig, "Rune slots",
            sprintf("%d/%d used", equipment->query("runes fused"),
                equipment->query("rune slots")));
        foreach (string runeName in runeNames)
        {
            mapping runeRecord = fusedRunes[runeName];
            string tier = runeRecord["rune tier"];
            string tierKey = tier ? sprintf("rune %s", tier) : "rune basic";

            string desc = runeRecord["description"] || runeName;
            string header = desc;
            string trailer = "";
            if (regexp(({ desc }), "(.+) (\\(.+\\))$"))
            {
                header = regreplace(desc, "^(.+) (\\(.+\\))$", "\\1", 1);
                trailer = regreplace(desc, "^(.+) (\\(.+\\))$", "\\2", 1);
            }

            ret += "      - " + configuration->decorate(header,
                tierKey, "equipment", colorConfig);

            if (sizeof(trailer))
            {
                string inner = regreplace(trailer, "^\\((.+)\\)$", "\\1", 1);
                string *parts = explode(inner, ", ");
                string *colored = ({});
                foreach (string part in parts)
                {
                    string partKey = regexp(({ part }), "^-") ?
                        "rune penalty" : "rune bonus";
                    colored += ({ configuration->decorate(part,
                        partKey, "equipment", colorConfig) });
                }
                ret += " (" + implode(colored, ", ") + ")";
            }
            ret += "\n";
        }
    }
    else if ((equipment->query("identified") || canCraft) &&
        equipment->query("rune slots") > 0)
    {
        ret += detailsText(colorConfiguration(initiator), "Rune slots",
            sprintf("%d (none fused)", equipment->query("rune slots")));
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

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getRangeMapping(int baseValue, float spread)
{
    return ([
        "min": to_int(baseValue - spread),
        "max": to_int(baseValue + spread)
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComponentDetails(object equipment)
{
    mapping ret = ([]);
    mapping craftingMaterials = equipment->query("crafting materials");

    if (craftingMaterials && mappingp(craftingMaterials))
    {
        string *components = filter(m_indices(craftingMaterials),
            (: mappingp($2[$1]) :), craftingMaterials);

        foreach(string component in components)
        {
            mapping componentData = craftingMaterials[component];
            mapping componentMaterials = ([]);

            foreach(string materialClass in materialClasses)
            {
                if (member(componentData, materialClass) &&
                    isValidMaterial(componentData[materialClass]))
                {
                    componentMaterials[materialClass] = ([
                        "material": componentData[materialClass],
                        "class": materials[componentData[materialClass]]["class"]
                    ]);
                }
            }

            ret[component] = ([
                "componentClass": component,
                "style": member(componentData, "type") ? componentData["type"] : 0,
                "materials": componentMaterials,
                "isPrimary": (component == equipment->query("primary component")) ? 1 : 0
            ]);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isMagicalItem(mapping enchantments, mapping resistances,
    mapping bonuses, object equipment)
{
    return sizeof(enchantments) || sizeof(resistances) || sizeof(bonuses) ||
        equipment->query("enchanted") || equipment->query("cursed");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getItemDetails(object equipment)
{
    mapping ret = ([]);

    if (isValidItem(equipment))
    {
        int identified = equipment->query("identified") ? 1 : 0;
        mapping enchantments = getEnchantmentMapping(equipment, 0);
        mapping resistances = getResistanceMapping(equipment, 0);
        mapping bonuses = getBonusMapping(equipment);
        int magical = isMagicalItem(enchantments, resistances, bonuses, equipment);

        ret = ([
            "identified": identified,
            "magical": magical ? 1 : 0,
            "quality": qualityTier(equipment),
            "description": equipment->query("long") || equipment->query("short"),
            "materialsDescription": getService("crafting")->getEquipmentMaterials(equipment),
            "material": equipment->query("material"),
            "weight": equipment->query("weight"),
            "encumberance": getEncumberanceData(equipment, 0),
            "runeSlots": equipment->query("rune slots") || 0,
            "runesFused": equipment->query("runes fused") || 0,
            "fusedRunes": equipment->query("runes fused") ? equipment->query("fused runes") || ([]) : ([]),
            "components": getComponentDetails(equipment)
        ]);

        // Magical properties (enchantments, resistances, bonuses, curses) are
        // only revealed once the item has been identified.
        if (!magical || identified)
        {
            ret["cursed"] = equipment->query("cursed") ? 1 : 0;
            ret["enchantments"] = enchantments;
            ret["resistances"] = resistances;
            ret["bonuses"] = bonuses;
        }

        if (equipment->query("weapon type"))
        {
            ret["weaponType"] = equipment->query("weapon type");

            if (!magical || identified)
            {
                int baseAttack = getAttackData(equipment, 0);
                int baseDamage = getDamageData(equipment, 0);
                int baseDefense = getWeaponDefenseData(equipment, 0);

                ret["attack"] = getRangeMapping(baseAttack, 100.0);
                ret["damage"] = getRangeMapping(baseDamage, baseDamage / 8.0);
                ret["defense"] = getRangeMapping(baseDefense, baseDefense / 8.0);
            }
        }
        else if (equipment->query("armor type"))
        {
            ret["armorType"] = equipment->query("armor type");

            if (!magical || identified)
            {
                ret["soak"] = getDamageProtectionData(equipment, 0);
            }
        }
    }

    return ret;
}

#endif

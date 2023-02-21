//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _enchantments_c
#define _enchantments_c

#include "/lib/dictionaries/materials/components/combat-properties.c"

/////////////////////////////////////////////////////////////////////////////
private nomask string convertDamageMappingToString(mapping damages, 
    object initiator)
{
    string ret = 0;

    if (damages && sizeof(damages))
    {
        ret = "";
        string *damagetKeys = sort_array(m_indices(damages),
            (: return $1 > $2; :));

        string colorConfiguration = colorConfiguration(initiator);

        foreach(string damage in damagetKeys)
        {
            ret += configuration->decorate(sprintf(" [+%d %s]", 
                damages[damage], damage), "bonus", "equipment", colorConfiguration);
        }
        ret += "\n";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string applyEnchantments(object weapon, object initiator)
{
    string ret = 0;

    mapping enchantments = weapon->query("enchantments");
    if (!enchantments)
    {
        enchantments = ([]);
    }

    string *extraDamages = hasExtraAttackTypes(weapon);
    if(sizeof(extraDamages))
    {
        foreach(string extraDamage in extraDamages)
        {
            enchantments[extraDamage] = member(enchantments, extraDamage) ?
                (enchantments[extraDamage] + getMaterialDamage(weapon, extraDamage)) :
                getMaterialDamage(weapon, extraDamage);
        }
    }

    return convertDamageMappingToString(enchantments, initiator);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string applyResistances(object item, object initiator)
{
    string ret = 0;

    mapping resistances = item->query("resistances");
    if (!resistances)
    {
        resistances = ([]);
    }

    string material = item->query("material");
    if (material && member(materials, material) &&
        member(materials[material], "defense") &&
        item->query("armor type"))
    {
        string *materialResistances = m_indices(materials[material]["defense"]);
        if (sizeof(materialResistances))
        {
            foreach(string materialResistance in materialResistances)
            {
                resistances[materialResistance] = member(resistances, materialResistance) ?
                    (resistances[materialResistance] + getMaterialDefense(item, materialResistance)) :
                    getMaterialDefense(item, materialResistance);
            }

            if (item->query("armor type") && member(resistances, "physical"))
            {
                m_delete(resistances, "physical");
            }
        }
    }

    return convertDamageMappingToString(resistances, initiator);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *bonusList(object item)
{
    string *bonuses = ({ "bonus strength", "bonus intelligence", "bonus dexterity",
        "bonus wisdom", "bonus constitution", "bonus charisma", "bonus armor class",
        "bonus defense class", "bonus attack", "bonus soak", "bonus defense",
        "bonus spell points", "bonus stamina points", "bonus heal hit points rate",
        "bonus heal hit points", "bonus heal spell points", "bonus hit points",
        "bonus heal spell points rate", "bonus heal stamina",
        "bonus heal stamina rate", "bonus damage", "bonus weapon attack" });

    if (item->query("weapon type"))
    {
        bonuses += ({ item->query("weapon type") });
    }
    else if (item->query("armor type"))
    {
        bonuses += ({ item->query("armor type") });
    }
    else
    {
        bonuses +=
            getDictionary("skills")->validBonusSkills();
    }
    return bonuses;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addEnchantment(object item)
{
    int ret = 0;

    string *enchantments = ({ "acid", "air", "chaos", "cold", "earth", "electricity",
        "energy", "fire", "magical", "poison", "water", "undead", "good", "evil" });

    string enchantType = "enchantments";
    if (item->query("armor type") ||
        (!item->query("weapon type") && random(2)))
    {
        enchantType = "resistances";
    }

    if (!item->query(enchantType))
    {
        string enchantment = enchantments[random(sizeof(enchantments))];
        item->set(enchantType, ([
            enchantment:(1 + random(5))
        ]));
        item->set("name", sprintf("%s of %s", item->query("name"), capitalize(enchantment)));
        item->set("short", sprintf("%s of %s", item->query("short"), capitalize(enchantment)));
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addEnchantments(object item, int numEnchantments)
{
    for (int j = 0; j < numEnchantments; j++)
    {
        switch (random(3))
        {
            case 0:
            case 1:
            {
                if (addEnchantment(item))
                {
                    break;
                }
            }
            default:
            {
                string *bonuses = bonusList(item);

                item->set(bonuses[random(sizeof(bonuses))],
                    (1 + random(3)));
            }
        }
        if (!random(4))
        {
            item->set("craftsmanship", getRandomCraftsmanshipBonus(item));
        }
    }
}

#endif

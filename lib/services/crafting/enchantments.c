//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _enchantment_c
#define _enchantment_c

#include "/lib/services/crafting/core.c"

/////////////////////////////////////////////////////////////////////////////
private nomask int getEnchantmentStrength(string enchantment, object user)
{
    int ret = user->researchBonusTo(sprintf("crafting %s", enchantment));

    mapping skills = equipmentEnchantments[enchantment]["crafting prerequisites"];

    if (sizeof(skills))
    {
        string *skillList = m_indices(skills);
        foreach(string skill in skillList)
        {
            if (skills[skill]["type"] == "skill")
            {
                ret += (user->getSkill(skill) - skills[skill]["value"]) / 10;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyEffects(string enchantment, object user, object item,
    int count)
{
    int ret = 1;

    int bonus = getEnchantmentStrength(enchantment, user);

    mapping effects = equipmentEnchantments[enchantment]["effects"] + ([]);
    foreach(string effect in m_indices(effects))
    {
        if (mappingp(effects[effect]))
        {
            foreach(string element in m_indices(effects[effect]))
            {
                effects[effect][element] = 
                    (effects[effect][element] + bonus) * count;
            }
        }
        else if(effect != "damage type")
        {
            effects[effect] = (effects[effect] + bonus) * count;
        }

        ret &&= item->set(effect, effects[effect]);
    }

    if (member(equipmentEnchantments[enchantment], "experience modifier"))
    {
        item->set("crafting experience", item->query("crafting experience") *
            equipmentEnchantments[enchantment]["experience modifier"]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyEnchantments(object item, object user)
{
    int ret = 1;
    mapping enchantments = item->query("crafting enchantments");
    if (!mappingp(enchantments))
    {
        enchantments = ([]);
    }
    string *enchantmentList = m_indices(enchantments);
    foreach(string enchantment in enchantmentList)
    {
        if (member(equipmentEnchantments, enchantment))
        {
            ret &&= applyEffects(enchantment, user, item, 
                enchantments[enchantment]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canEnchantItem(object item, object user)
{
    return user->isResearched("/lib/instances/research/crafting/enchantments/craftEnchantments.c");
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int addEnchantment(object item, string enchantment, int decrement)
{
    int ret = 1;
    mapping craftingEnchantments = item->query("crafting enchantments");
    if (!mappingp(craftingEnchantments))
    {
        craftingEnchantments = ([]);
    }
    if (member(equipmentEnchantments, enchantment))
    {
        int newLevel = decrement ? -1 : 1;
        if (member(craftingEnchantments, enchantment))
        {
            newLevel += craftingEnchantments[enchantment];
        }
        if (newLevel < 0)
        {
            newLevel = 0;
        }

        if (!newLevel)
        {
            m_delete(craftingEnchantments, enchantment);
        }
        else if (newLevel < 4)
        {
            craftingEnchantments[enchantment] = newLevel;
        }
        else
        {
            ret = 0;
        }

        if (sizeof(craftingEnchantments))
        {
            item->set("crafting enchantments", craftingEnchantments);
        }
        else
        {
            item->unset("crafting enchantments");
        }
    }
    return ret;
}

#endif

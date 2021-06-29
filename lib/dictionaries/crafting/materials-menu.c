//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _materials_menu_c
#define _materials_menu_c

#include "/lib/dictionaries/crafting/materials.c"

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getMaterialsOfTypeOnHand(string type, object user, 
    object craftingItem)
{
    mapping ret = ([]);

    object *inventory = filter(deep_inventory(user),
        (: ((member(inherit_list($1), "/lib/items/material.c") > -1) &&
            (member($2, $1->query("class")) > -1)) :), 
        getDictionary("materials")->getTypes(type, user));

    if (sizeof(inventory))
    {
        mapping materialsToBeUsed = materialsUsedForCrafting(craftingItem);
        foreach(object item in inventory)
        {
            string material = item->query("blueprint");
            if (!member(ret, material))
            {
                ret[material] = 0;
            }
            ret[material] += item->query("quantity");
            if (member(materialsToBeUsed, material))
            {
                ret[material] -= materialsToBeUsed[material];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getMaterialsOfType(string type, object user,
    int quantity, object craftingItem)
{
    mapping ret = ([]);

    object materialDictionary = getDictionary("materials");

    mapping materialsOnHand = getMaterialsOfTypeOnHand(type, user, craftingItem);
    string *materialsOfType = sort_array(filter(m_indices(materials),
        (: (member($2, materials[$1]["class"]) > -1) :), 
        materialDictionary->getTypes(type, user)),
        (: $1 > $2 :));

    if(sizeof(materialsOfType))
    {
        int menuItem = 1;
        string currentMaterial = craftingItem->query("material");

        foreach(string material in materialsOfType)
        {
            int hasMaterials = (member(materialsOnHand, material) &&
                (materialsOnHand[material] >= quantity));

            object blueprintObj = getBlueprintItem("materials", material);
            int prerequisites = prerequisitesMet(blueprintObj, user);

            craftingItem->set("material", material);

            string name = capitalize(material);
            if (sizeof(name) > 20)
            {
                name = name[0..16] + "...";
            }
            ret[to_string(menuItem)] = ([
                "name": name,
                "type": material,
                "description": sprintf("This option lets you craft using: %s\n%s\n", 
                    material, materialDictionary->getEquipmentStatistics(craftingItem, user)),
                "has materials": hasMaterials,
                "prerequisites met": prerequisites,
                "canShow": (hasMaterials && prerequisites)
            ]);
            menuItem++;
        }
        craftingItem->set("material", currentMaterial);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int allComponentsHaveBeenChosen(object item)
{
    int ret = 0;
    mapping materialsToUse = item->query("crafting materials");

    object blueprintObj = getBlueprintFor(item);
    mapping blueprintMaterials = blueprintObj->query("crafting materials");

    if (sizeof(blueprintMaterials) && sizeof(materialsToUse))
    {
        ret = 1;
        string *materialList = m_indices(blueprintMaterials);
        foreach(string material in materialList)
        {
            ret &&= member(materialsToUse, material);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void applyCraftingBonuses(object item, object user)
{
    string *craftingBonuses = validCraftingBonuses();
    foreach(string bonus in craftingBonuses)
    {
        int bonusValue = user->researchBonusTo(bonus);
        if (bonusValue)
        {
            item->set(bonus, bonusValue);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCraftingSkill(string type, string item, 
    object target, object user)
{
    object blueprintObj = getBlueprintItem(type, item);
    string *skills = blueprintObj->query("crafting skills");
    if (sizeof(skills))
    {
        int craftingSkill = 0;
        foreach(string skill in skills)
        {
            craftingSkill += user->getSkill(skill);
        }
        target->set("craftsmanship", craftingSkill);
    }
}

#endif

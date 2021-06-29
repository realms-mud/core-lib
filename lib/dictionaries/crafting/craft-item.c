//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _craft_item_c
#define _craft_item_c

#include "/lib/dictionaries/crafting/materials.c"
#include "/lib/dictionaries/crafting/enchantments.c"

/////////////////////////////////////////////////////////////////////////////
private nomask int useCraftingMaterial(object user, string materialName, int quantity)
{
    int ret = 0;
    object *inventory = filter(deep_inventory(user),
        (: ((member(inherit_list($1), "/lib/items/material.c") > -1) && 
            $1->id($2)) :), materialName);

    if (sizeof(inventory))
    {
        int quantityLeft = quantity;
        foreach(object item in inventory)
        {
            int itemQuantity = item->query("quantity");

            if (itemQuantity >= quantityLeft)
            {
                itemQuantity -= quantityLeft;
                quantityLeft = 0;
                if (itemQuantity > 0)
                {
                    item->set("quantity", itemQuantity);
                }
                else
                {
                    destruct(item);
                }
            }
            else
            {
                quantityLeft -= itemQuantity;
                destruct(item);
            }
        }
        ret = (quantityLeft == 0);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void updateItemExperience(object item)
{
    mapping craftingMaterials = item->query("crafting materials");
    if (craftingMaterials && mappingp(craftingMaterials))
    {
        string *components = filter(m_indices(craftingMaterials),
            (: mappingp($2[$1]) :), craftingMaterials);

        if (sizeof(components))
        {
            foreach(string component in components)
            {
                string key = craftingMaterials[component]["type"];

                item->set("crafting experience", 
                    item->query("crafting experience") *
                    (member(craftingComponents[key], "experience modifier") ?
                        craftingComponents[key]["experience modifier"] : 1.0));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int craftItem(object item, object user)
{
    int canCraft = 0;
    mapping materialsUsed = materialsUsedForCrafting(item);

    updateItemExperience(item);

    if (sizeof(materialsUsed))
    {
        canCraft = 1;
        string *materialsToRemove = m_indices(materialsUsed);
        foreach(string material in materialsToRemove)
        {
            canCraft &&= useCraftingMaterial(user, material, 
                materialsUsed[material]);
        }
    }
    canCraft &&= applyEnchantments(item, user);

    return canCraft;
}

#endif

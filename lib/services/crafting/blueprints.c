//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _blueprints_c
#define _blueprints_c

#include "/lib/services/crafting/core.c"

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getBlueprintsByType(string type)
{
    mapping items = ([]);
    switch (type)
    {
        case "armor":
        {
            items = armorBlueprints;
            break;
        }
        case "weapons":
        {
            items = weaponBlueprints;
            break;
        }
        case "materials":
        {
            items = materials;
            break;
        }
        case "components":
        {
            items = craftingComponents;
            break;
        }
        case "enchantments":
        {
            items = equipmentEnchantments;
            break;
        }
        default:
        {
            items = ([]);
        }
    }
    return items + ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask object getBlueprintFor(object item)
{
    object blueprintObj = 0;
    string blueprint = item->query("blueprint");
    if (member(BlueprintObjects, blueprint) &&
        objectp(BlueprintObjects[blueprint]))
    {
        blueprintObj = BlueprintObjects[blueprint];
    }
    else
    {
        mapping items = ([]);
        string *itemInheritance = inherit_list(item);

        if (member(itemInheritance, "/lib/items/armor.c") > -1)
        {
            items = armorBlueprints;
        }
        else if (member(itemInheritance, "/lib/items/weapon.c") > -1)
        {
            items = weaponBlueprints;
        }
        else if (member(itemInheritance, "/lib/items/material.c") > -1)
        {
            items = materials;
        }

        blueprintObj = clone_object("/lib/items/craftingBlueprint.c");
        if (sizeof(items) && member(items, blueprint))
        {
            blueprintObj->set("blueprint data", items[blueprint]);
            blueprintObj->set("blueprint", blueprint);
            BlueprintObjects[blueprint] = blueprintObj;
        }
        else
        {
            blueprintObj = 0;
        }
    }
    return blueprintObj;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask object getBlueprintItem(string type, string item)
{
    object blueprintObj = 0;
    if (member(BlueprintObjects, item) &&
        objectp(BlueprintObjects[item]))
    {
        blueprintObj = BlueprintObjects[item];
    }
    else
    {
        blueprintObj = clone_object("/lib/items/craftingBlueprint.c");
        mapping blueprints = getBlueprintsByType(type);

        if (sizeof(blueprints) && member(blueprints, item))
        {
            blueprintObj->set("blueprint data", blueprints[item]);
            blueprintObj->set("blueprint", item);
            BlueprintObjects[item] = blueprintObj;
        }
    }
    return blueprintObj;
}

#endif

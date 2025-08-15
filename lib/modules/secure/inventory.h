//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef inventoryModule_h
#define inventoryModule_h

#include "/lib/include/inventory.h"

private int money;

private nosave string ArmorBlueprint = "/lib/items/armor.c";
private nosave string WeaponBlueprint = "/lib/items/weapon.c";
private nosave string InstrumentBlueprint = "/lib/items/instrument.c";

private nosave string ModifierBlueprint = "/lib/items/modifierObject.c";
private nosave int weight = 0;

private mapping itemRegistry =
([
    "equipped":([
        "wielded primary":0,
        "wielded offhand" : 0,
        "armor" : 0,
        "gloves" : 0,
        "helmet" : 0,
        "boots" : 0,
        "ring 1" : 0,
        "ring 2" : 0,
        "cloak" : 0,
        "amulet" : 0,
        "belt" : 0,
        "arm greaves" : 0,
        "leg greaves" : 0,
        "bracers" : 0
    ]),
    "guild objects": ([
    ])
]);

/////////////////////////////////////////////////////////////////////////////
static nomask void loadInventory(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence) && member(data, "inventory"))
    {
        money = persistence->extractSaveData("money", data);
        mapping items = persistence->extractSavedMapping("inventory", data);

        if (sizeof(items))
        {
            string *itemList = m_indices(items);
            if (sizeof(itemList))
            {
                int haveLoadErrors = 0;
                string errors = 0;
                string failedLoad = "";
                object configuration = getService("configuration");
                string colorConfig = this_player() ?
                    this_player()->colorConfiguration() : "none";

                foreach(string item in itemList)
                {
                    object itemObject;
                    errors = catch(itemObject = 
                        clone_object(regreplace(item, "#[0-9]+$", ".c", 1)));

                    if (itemObject && objectp(itemObject))
                    {
                        itemObject->set("all", items[item]["data"]);
                        errors = catch(move_object(itemObject, this_object()));

                        if (!errors && items[item]["isEquipped"] &&
                            ((member(inherit_list(itemObject), ArmorBlueprint) > -1) ||
                            (member(inherit_list(itemObject), WeaponBlueprint) > -1)))
                        {
                            string equipString = itemObject->query("name");
                            if (itemObject->query("equipment locations") == Ring2)
                            {
                                equipString = "second " + equipString;
                            }
                            
                            itemObject->equip(equipString);
                        }
                        else if (!errors && items[item]["isEquipped"] &&
                            (member(inherit_list(itemObject), ModifierBlueprint) > -1))
                        {
                            this_object()->registerObjectAsInventory(itemObject);
                        }
                        if (errors && itemObject)
                        {
                            destruct(itemObject);
                        }
                    }

                    if (errors)
                    {
                        failedLoad += configuration->decorate(
                            sprintf("    %O\n", item),
                                "value", "equipment", colorConfig);
                        haveLoadErrors = 1;
                        errors = 0;
                    }
                }

                if (haveLoadErrors && this_player())
                {
                    tell_object(this_player(),
                        configuration->decorate(
                            "Failed to load an item in your inventory: \n",
                            "error message", "equipment", colorConfig) +
                        failedLoad + "\n");
                }
            }
            this_object()->resetCombatCache();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendInventory()
{
    mapping ret = ([
        "money": money,
        "inventory": ([]) 
    ]);

    object *registeredObjects = m_values(itemRegistry["guild objects"]) - 
        ({ 0 });
    if (sizeof(registeredObjects))
    {
        foreach(object registeredObject in registeredObjects)
        {
            if (find_object(object_name(registeredObject)))
            {
                ret["inventory"][object_name(registeredObject)] = ([
                    "data":registeredObject->query("all"),
                    "isEquipped": 1
                ]);
            }
        }
    }

    object *inventoryObjects = filter(all_inventory(),
        (: ((member(inherit_list($1), "/lib/core/baseSelector.c") < 0) &&
           (member(inherit_list($1), "/lib/modules/guilds/researchChooser.c") < 0) &&
           (member(inherit_list($1), "/lib/items/modifierObject.c") < 0)) :))
        - registeredObjects;
    {
        foreach(object inventoryObject in inventoryObjects)
        {
            ret["inventory"][object_name(inventoryObject)] = ([
                "data":inventoryObject->query("all"),
                "isEquipped": (member(m_values(itemRegistry["equipped"]), inventoryObject) > -1)
            ]);
        }
    }
    return ret;
}

#endif

//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int money;

private nosave string ArmorBlueprint = "lib/items/armor.c";
private nosave string WeaponBlueprint = "lib/items/weapon.c";
private nosave string ModifierBlueprint = "lib/items/modifierObject.c";
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
                foreach(string item in itemList)
                {
                    object itemObject = clone_object(regreplace(item, "#[0-9]+$", ".c", 1));
                    if (itemObject && objectp(itemObject))
                    {
                        itemObject->set("all", items[item]["data"]);
                        move_object(itemObject, this_object());

                        if (items[item]["isEquipped"] && 
                            ((member(inherit_list(itemObject), ArmorBlueprint) > -1) ||
                            (member(inherit_list(itemObject), WeaponBlueprint) > -1)))
                        {
                            itemObject->equip(itemObject->query("name"));
                        }
                        else if (items[item]["isEquipped"] &&
                            (member(inherit_list(itemObject), ModifierBlueprint) > -1))
                        {
                            this_object()->registerObjectAsInventory(itemObject);
                        }
                    }
                }
            }
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

    object *registeredObjects = m_values(itemRegistry["guild objects"]);
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

    object *inventoryObjects = all_inventory() - registeredObjects;
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

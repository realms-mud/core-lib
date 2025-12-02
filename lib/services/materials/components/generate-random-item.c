//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _generate_random_item_c
#define _generate_random_item_c

#include "/lib/services/materials/components/enchantments.c"

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string *getListOfBlueprints(string type, string subtype,
    string *listOfPotentialItems)
{
    string *itemBlueprints = ({});
    string *validTypes = get_dir("/lib/instances/items/*") - 
        ({ ".", ".." });

    if (listOfPotentialItems)
    {
        foreach(string file in listOfPotentialItems)
        {
            if (sizeof(regexp(({ file }), "/")))
            {
                itemBlueprints += ({ file });
            }
            else if (member(validTypes, type) > -1)
            {
                string item = sprintf("/lib/instances/items/%s%s/%s.c",
                    type, (subtype && (subtype != "")) ? "/" + subtype : "",
                    file);

                item = regreplace(item, " ", "-", 1);
                item = regreplace(item, "'", "", 1);

                itemBlueprints += ({ item });
            }
        }
    }
    else if (stringp(subtype) && sizeof(regexp(({ subtype }), "^[a-z-]+/[a-z-]+")))
    {
        itemBlueprints += 
            ({ sprintf("/lib/instances/items/%s/%s.c", type, subtype ) });
    }
    else
    {
        string directory = sprintf("/lib/instances/items/%s%s/", type,
            ((subtype && (subtype != "")) ? "/" + subtype : ""));

        directory = regreplace(directory, " ", "-", 1);
        directory = regreplace(directory, "'", "", 1);

        itemBlueprints = get_dir(directory + "*", 0x10) - 
            ({ directory + ".", directory + ".." });
    }
    return itemBlueprints;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs object getRandomItemOfType(string type, string subtype,
    string *listOfPotentialItems)
{
    object item = 0;

    string *itemBlueprints = getListOfBlueprints(type, subtype, 
        listOfPotentialItems);

    if (sizeof(itemBlueprints))
    {
        string blueprint = itemBlueprints[random(sizeof(itemBlueprints))];

        if (file_size(blueprint) == -2)
        {
            string *subList = get_dir(blueprint + "/*") - 
                ({ ".", ".." });
            blueprint += "/" + subList[random(sizeof(subList))];
        }

        if (file_size(blueprint) > 0)
        {
            item = clone_object(blueprint);
        }
    }
    return item;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs object generateRandomItem(string type, string subtype, 
    int chanceForMagicalItems, string *listOfPotentialItems)
{
    object item = 0;

    object craftingService = getService("crafting");

    item = getRandomItemOfType(type, subtype, listOfPotentialItems);
    if (objectp(item))
    {
        craftingService->getRandomCraftingMaterial(item);

        string *aliases = ({ lower_case(item->query("name")) });
        if (item->query("aliases"))
        {
            aliases += item->query("aliases");
        }
        item->set("aliases", aliases);

        if (random(100) < chanceForMagicalItems)
        {
            addEnchantments(item, 1 + random(5));
        }

        if (member(({ "rod", "wand" }), item->query("name")) > -1)
        {
            string *possibleDamageTypes = ({ "acid", "air", "chaos", "cold",
                "earth", "electricity", "energy", "fire", "magical", "poison",
                "water", "undead", "good", "evil", "psionic", "sonic" });
            string damageType =
                possibleDamageTypes[random(sizeof(possibleDamageTypes))];

            item->set("primary damage type", damageType);
            item->set("name", sprintf("%s %s", capitalize(damageType),
                item->query("name")));
            item->set("short", sprintf("%s %s", capitalize(damageType),
                item->query("short")));
        }
    }
    return item;
}

#endif

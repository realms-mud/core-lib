//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/items/equipment.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "type":
        {
            ret = "instrument";
            break;
        }
        case "blueprint":
        {
            ret = member(itemData, "blueprint") ? itemData["blueprint"] :
                equipment::query("instrument type");
            break;
        }
        case "instrument type":
        {
            ret = member(itemData, "instrument type") ? itemData["instrument type"] :
                materialsObject()->getBlueprintDetails(this_object(), "skill to use");
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of a musical instrument";
            break;
        }
        case "dim light description":
        {
            ret = "An apparent " + query("instrument type");
            break;
        }
        case "some light description":
        {
            ret = query("instrument type");
            break;
        }
        case "crafting guilds":
        {
            object guilds = load_object("/lib/dictionaries/guildsDictionary.c");
            if (guilds)
            {
                ret = guilds->guildsInClass("crafting");
            }
            break;
        }
        default:
        {
            ret = equipment::query(element);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void generateRandomCraftingMaterials()
{
    if (!query("crafting materials"))
    {
        getDictionary("crafting")->getRandomCraftingMaterial(
            this_object(), 1);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkBlueprint(string data)
{
    int ret = 0;
    if (data && stringp(data))
    {
        ret = materialsObject()->isValidInstrumentBlueprint(data);
    }

    if (ret)
    {
        itemData["blueprint"] = data;
        call_out("generateRandomCraftingMaterials", 1);
    }
    else
    {
        raise_error(sprintf("Instrument: The 'blueprint' element must be"
            " a string as defined in the keys of the instrumentBlueprints"
            " mapping in %s.\n",
            MaterialsBlueprint));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int ret = 0;

    if (element && stringp(element))
    {
        switch (element)
        {
            case "blueprint":
            {
                ret = checkBlueprint(data);
                break;
            }
            default:
            {
                ret = equipment::set(element, data);
            }
        }
    }
    return ret;
}

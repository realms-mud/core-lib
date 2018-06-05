//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch (element)
    {
        case "type":
        {
            ret = "potion";
            break;
        }
        case "blueprint":
        {
            ret = member(itemData, "blueprint") ? itemData["blueprint"] :
                "item"::query("potion type");
            break;
        }
        case "potion type":
        {
            ret = member(itemData, "potion type") ? itemData["potion type"] :
                materialsObject()->getBlueprintModifier(this_object(), "skill to use");
            break;
        }
        default:
        {
            ret = "item"::query(element);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkBlueprint(string data)
{
    int ret = 0;
    if (data && stringp(data))
    {
        ret = materialsObject()->isValidPotionBlueprint(data);
    }

    if (ret)
    {
        itemData["blueprint"] = data;
    }
    else
    {
        raise_error(sprintf("Potion: The 'blueprint' element must be"
            " a string as defined in the keys of the potions"
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
            ret = "item"::set(element, data);
        }
        }
    }
    return ret;
}

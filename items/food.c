//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "type":
        {
            ret = "food";
            break;
        }
        case "blueprint":
        {
            ret = member(itemData, "blueprint") ? itemData["blueprint"] :
                "item"::query("food type");
            break;
        }
        case "food type":
        {
            ret = member(itemData, "food type") ? itemData["food type"] :
                materialsObject()->getBlueprintModifier(this_object(), "skill to use");
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of an object";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be food";
            break;
        }
        case "some light description":
        {
            ret = query("food type");
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
        ret = materialsObject()->isValidFoodBlueprint(data);
    }

    if (ret)
    {
        itemData["blueprint"] = data;
    }
    else
    {
        raise_error(sprintf("Food: The 'blueprint' element must be"
            " a string as defined in the keys of the food"
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

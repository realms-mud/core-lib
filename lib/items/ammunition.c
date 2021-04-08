//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
            ret = "ammunition";
            break;
        }
        case "remaining capacity":
        {
            ret = itemData["max capacity"] - itemData["quantity"];
            break;
        }
        case "short":
        {
            ret = item::query("short");
            if ((isIlluminated() > 8) && itemData["ammunition type"])
            {
                if (itemData["quantity"])
                {
                    ret += sprintf(" containing %d %s%s (%d max)",
                        itemData["quantity"],
                        itemData["ammunition type"],
                        (itemData["quantity"] == 1) ? "" : "s",
                        itemData["max capacity"]);
                }
                else
                {
                    ret += sprintf(" that is empty (%d max)",
                        itemData["max capacity"]);
                }
            }
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of a small, rectangular object";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be an ammunition container";
            break;
        }
        default:
        {
            ret = item::query(element);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addAmmunition(int amount)
{
    int ret = 0;

    if (amount > 0)
    {
        if (!member(itemData, "quantity"))
        {
            itemData["quantity"] = 0;
        }

        int remainingCapacity = query("remaining capacity");
        if (amount > remainingCapacity)
        {
            itemData["quantity"] += remainingCapacity;
            ret = amount - remainingCapacity;
        }
        else
        {
            itemData["quantity"] += amount;
        }
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
            case "ammunition type":
            {
                if (stringp(data))
                {
                    ret = 1;
                    itemData["ammunition type"] = data;
                }
                break;
            }
            case "max capacity":
            {
                if (intp(data))
                {
                    ret = 1;
                    itemData["max capacity"] = data;
                }
                break;
            }
            case "quantity":
            {
                if (intp(data) && member(itemData, "max capacity"))
                {
                    ret = 1;
                    itemData["quantity"] = data;
                }
                else
                {
                    raise_error("ammunition.c: 'max capacity' must be set before "
                        "quantity");
                }
                break;
            }
            default:
            {
                ret = item::set(element, data);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int doNotDestroyWhenConsumed()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return (item == itemData["ammunition type"]) ||
        item::id(item);
}

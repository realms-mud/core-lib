//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
private string determineShortDescription()
{
    string ret = "A coin";
    int value = query("value");
    if (value > 1)
    {
        ret = sprintf("A pile of %d coins", value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "name":
        case "type":
        {
            ret = "money";
            break;
        }
        case "aliases":
        {
            ret = ({ "money", "coin", "coins", "currency", "pile of money", "pile of coins" });
            break;
        }
        case "short":
        {
            if (query("value") < 1)
            {
                set("value", 1);
            }
            ret = determineShortDescription();
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of an object";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be money";
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
public varargs int get()
{
    int ret = !query("ungettable");
    return ret;
}

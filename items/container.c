//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";
#include "/lib/include/itemFormatters.h"

/////////////////////////////////////////////////////////////////////////////
public int isContainer()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int canGet(object target)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "type":
        {
            ret = "container";
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of an item";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be a container";
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
private nomask string colorizeText(object item)
{
    string ret = "";

    if (item && item->short())
    {
        if (materialsObject())
        {
            ret = materialsObject()->applyMaterialQualityToText(item, item->short());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string inventoryText(object *itemList)
{
    string ret = "";

    foreach(object equipment in itemList)
    {
        if (equipment->short())
        {
            ret += sprintf(Red, "| ") + colorizeText(equipment) + "\n";
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string long(int doNotApplyUserStatistics)
{
    string ret = "item"::long(doNotApplyUserStatistics);

    object *inventory = sort_array(all_inventory(), 
        (: object_name($1) < object_name($2) :));

    if (sizeof(inventory))
    {
        ret += "\nThis item contains the following:\n" +
            inventoryText(inventory);
    }
    return ret;
}

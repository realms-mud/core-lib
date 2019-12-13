//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

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
private nomask varargs string colorizeText(object item, int quantity)
{
    string ret = "";

    if (item && item->short())
    {
        if (materialsObject())
        {
            string itemDesc = item->short(1);
            if (!quantity)
            {
                if (sizeof(itemDesc) > 19)
                {
                    itemDesc = itemDesc[0..16] + "...";
                }
                itemDesc = sprintf("%-21s", itemDesc);
            }
            else
            {
                if (quantity > 1)
                {
                    itemDesc = sprintf("[%s] %s",
                        ((quantity > 99) ? "++" : to_string(quantity)),
                        itemDesc);
                }
                if (sizeof(itemDesc) > 23)
                {
                    itemDesc = itemDesc[0..20] + "...";
                }
                itemDesc = sprintf("%-25s", itemDesc);
            }

            ret = materialsObject()->applyMaterialQualityToText(item,
                itemDesc, this_object());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string inventoryText(object *allItems)
{
    string ret = "";

    string colorConfiguration = this_player() ?
        this_player()->colorConfiguration() : "none";
    string charset = this_player() ?
        this_player()->charsetConfiguration() : "ascii";
    object banner = load_object("/lib/dictionaries/commandsDictionary.c");

    if (sizeof(allItems))
    {
        ret += banner->buildBanner(colorConfiguration, charset,
            "top", "This item contains the following");
    }

    mapping otherItems = ([]);
    foreach(object equipment in allItems)
    {
        string key = program_name(equipment) + "#" + equipment->short(1);

        if (member(otherItems, key))
        {
            otherItems[key]++;
            allItems -= ({ equipment });
        }
        else
        {
            otherItems[key] = 1;
        }
    }

    string *itemList = ({});

    foreach(object equipment in allItems)
    {
        string key = program_name(equipment) + "#" + equipment->short(1);
        itemList += ({ colorizeText(equipment, otherItems[key]) });
        if ((sizeof(itemList) % 4) == 3)
        {
            ret += banner->banneredContent(colorConfiguration, charset,
                implode(itemList, ""));
            itemList = ({});
        }
    }

    if (sizeof(itemList))
    {
        for (int i = sizeof(itemList); i < 3; i++)
        {
            itemList += ({ sprintf("%-25s", "") });
        }

        ret += banner->banneredContent(colorConfiguration, charset,
            implode(itemList, ""));
    }
    ret += banner->buildBanner(colorConfiguration, charset, "bottom", "", "", 1);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string long(int doNotApplyUserStatistics)
{
    string ret = "item"::long(doNotApplyUserStatistics);

    object *inventory = sort_array(all_inventory(), 
        (: $1->query("short") > $2->query("short") :));

    if (sizeof(inventory))
    {
        ret += inventoryText(inventory);
    }
    return ret;
}

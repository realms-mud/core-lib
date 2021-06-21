//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/crafting/blueprints.c";

/////////////////////////////////////////////////////////////////////////////
private nomask string *getEquipmentSubTypes(string type)
{
    string *ret = ({});
    mapping items = getBlueprintsByType(type);
    string *indices = m_indices(items);

    if (sizeof(indices))
    {
        foreach(string item in indices)
        {
            if (member(ret, items[item]["subtype"]) < 0)
            {
                ret += ({ items[item]["subtype"] });
            }
        }
    }
    return sort_array(ret, (: $1 > $2 :));
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCraftingList(string type, object user)
{
    mapping ret = ([]);
    string *itemSubtypes = getEquipmentSubTypes(type);

    int menuItem = 1;
    if (sizeof(itemSubtypes))
    {
        foreach(string item in itemSubtypes)
        {
            ret[to_string(menuItem)] = ([
                "name": capitalize(item),
                "description": sprintf("This option lets you craft: %s\n", item),
                "selector": type,
                "sub type": item,
                "canShow": 1
            ]);
            menuItem++;
        }
    }
    return ret;
}

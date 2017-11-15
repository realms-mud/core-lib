//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

mapping list = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask int storeItem(object item)
{
    int ret = 0;

    if (item && (member(inherit_list(item), "lib/items/item.c") > -1) &&
        !item->query("cursed") && !item->query("no sell"))
    {

    }
}

/////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Evil Resistance");
        set("short", "Potion of Evil Resistance");
        set("aliases", ({ "evil resistance", "potion", "evil resistance potion",
            "potion of evil resistance" }));
        set("blueprint", "evil resistance potion");
    }
}

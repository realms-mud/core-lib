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
        set("name", "Potion of Constitution");
        set("short", "Potion of Constitution");
        set("aliases", ({ "constitution", "potion", "constitution potion",
            "potion of constitution" }));
        set("blueprint", "constitution");
    }
}

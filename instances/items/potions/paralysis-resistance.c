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
        set("name", "Potion of Paralysis Resistance");
        set("short", "Potion of Paralysis Resistance");
        set("aliases", ({ "paralysis resistance", "potion", "paralysis resistance potion",
            "potion of paralysis resistance" }));
        set("blueprint", "paralysis resistance");
    }
}

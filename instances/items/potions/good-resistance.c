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
        set("name", "Potion of Good Resistance");
        set("short", "Potion of Good Resistance");
        set("aliases", ({ "good resistance", "potion", "good resistance potion",
            "potion of good resistance" }));
        set("blueprint", "good resistance potion");
    }
}

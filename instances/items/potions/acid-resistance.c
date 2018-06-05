//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Acid Resistance");
        set("short", "Potion of Acid Resistance");
        set("aliases", ({ "acid resistance", "potion", "acid resistance potion",
            "potion of acid resistance" }));
        set("blueprint", "acid resistance");
    }
}

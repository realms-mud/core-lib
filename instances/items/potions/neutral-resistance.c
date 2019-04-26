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
        set("name", "Potion of Neutral Resistance");
        set("short", "Potion of Neutral Resistance");
        set("aliases", ({ "neutral resistance", "potion", "neutral resistance potion",
            "potion of neutral resistance" }));
        set("blueprint", "neutral resistance potion");
    }
}

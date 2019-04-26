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
        set("name", "Potion of Cold Resistance");
        set("short", "Potion of Cold Resistance");
        set("aliases", ({ "cold resistance", "potion", "cold resistance potion",
            "potion of cold resistance" }));
        set("blueprint", "cold resistance potion");
    }
}

//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Chaos Resistance");
        set("short", "Potion of Chaos Resistance");
        set("aliases", ({ "chaos resistance", "potion", "chaos resistance potion",
            "potion of chaos resistance" }));
        set("blueprint", "chaos resistance potion");
    }
}

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
        set("name", "Potion of Sonic Resistance");
        set("short", "Potion of Sonic Resistance");
        set("aliases", ({ "sonic resistance", "potion", "sonic resistance potion",
            "potion of sonic resistance" }));
        set("blueprint", "sonic resistance potion");
    }
}

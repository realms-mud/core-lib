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
        set("name", "Potion of Speed");
        set("short", "Potion of Speed");
        set("aliases", ({ "speed", "potion", "speed potion",
            "potion of speed" }));
        set("blueprint", "speed potion");
    }
}

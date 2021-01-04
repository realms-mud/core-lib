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
        set("name", "Potion of Dexterity");
        set("short", "Potion of Dexterity");
        set("aliases", ({ "dexterity", "potion", "dexterity potion",
            "potion of dexterity" }));
        set("blueprint", "dexterity potion");
    }
}

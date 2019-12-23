//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Intelligence");
        set("short", "Potion of Intelligence");
        set("aliases", ({ "intelligence", "potion", "intelligence potion",
            "potion of intelligence" }));
        set("blueprint", "intelligence potion");
    }
}

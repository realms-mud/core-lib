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
        set("name", "Mana Potion");
        set("short", "Mana Potion");
        set("aliases", ({ "mana", "potion", "mana potion" }));
        set("blueprint", "mana potion");
    }
}

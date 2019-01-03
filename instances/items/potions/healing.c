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
        set("name", "Healing Potion");
        set("short", "Healing Potion");
        set("aliases", ({ "healing", "potion", "healing potion" }));
        set("blueprint", "healing");
    }
}

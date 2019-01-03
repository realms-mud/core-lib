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
        set("name", "Stamina Potion");
        set("short", "Stamina Potion");
        set("aliases", ({ "stamina", "potion", "stamina potion" }));
        set("blueprint", "stamina");
    }
}

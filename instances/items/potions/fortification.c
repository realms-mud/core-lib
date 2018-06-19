//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Fortification");
        set("short", "Potion of Fortification");
        set("aliases", ({ "fortification", "potion", "fortification potion",
            "potion of fortification" }));
        set("blueprint", "fortification");
    }
}

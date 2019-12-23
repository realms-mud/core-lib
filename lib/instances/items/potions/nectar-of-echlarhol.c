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
        set("name", "Nectar of Echlarhol");
        set("short", "Nectar of Echlarhol");
        set("aliases", ({ "nectar", "potion", "nectar of echlarhol" }));
        set("blueprint", "nectar of echlarhol");
    }
}

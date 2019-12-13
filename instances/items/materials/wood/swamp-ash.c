//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Swamp ash");
        set("short", "Swamp ash");
        set("aliases", ({ "wood", "swamp ash" }));
        set("blueprint", "swamp ash");
    }
}

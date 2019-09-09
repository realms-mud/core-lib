//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Pear");
        set("short", "Pear (Wood)");
        set("aliases", ({ "wood", "pear" }));
        set("blueprint", "pear");
    }
}

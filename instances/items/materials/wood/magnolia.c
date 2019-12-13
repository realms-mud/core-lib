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
        set("name", "Magnolia");
        set("short", "Magnolia (Wood)");
        set("aliases", ({ "wood", "magnolia" }));
        set("blueprint", "magnolia");
    }
}

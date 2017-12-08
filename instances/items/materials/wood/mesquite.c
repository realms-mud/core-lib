//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Mesquite");
        set("short", "Mesquite");
        set("aliases", ({ "wood" }));
        set("blueprint", "mesquite");
    }
}

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
        set("name", "Beech");
        set("short", "Beech (Wood)");
        set("aliases", ({ "wood", "beech" }));
        set("blueprint", "beech");
    }
}

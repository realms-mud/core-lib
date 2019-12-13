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
        set("name", "Albatross Feather");
        set("short", "Albatross Feather");
        set("aliases", ({ "feather", "albatross feather" }));
        set("blueprint", "albatross feather");
    }
}

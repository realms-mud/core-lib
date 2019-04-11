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
        set("name", "Starling Feather");
        set("short", "Starling Feather");
        set("aliases", ({ "feather", "starling feather" }));
        set("blueprint", "starling feather");
    }
}

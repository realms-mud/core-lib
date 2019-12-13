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
        set("name", "Oriol Feather");
        set("short", "Oriol Feather");
        set("aliases", ({ "feather", "oriol feather" }));
        set("blueprint", "oriol feather");
    }
}

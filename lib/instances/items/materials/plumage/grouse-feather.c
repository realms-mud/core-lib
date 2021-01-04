//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Grouse Feather");
        set("short", "Grouse Feather");
        set("aliases", ({ "feather", "grouse feather" }));
        set("blueprint", "grouse feather");
    }
}

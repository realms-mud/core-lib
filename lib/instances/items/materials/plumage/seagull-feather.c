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
        set("name", "Seagull Feather");
        set("short", "Seagull Feather");
        set("aliases", ({ "feather", "seagull feather" }));
        set("blueprint", "seagull feather");
    }
}

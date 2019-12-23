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
        set("name", "Barn Swallow Feather");
        set("short", "Barn Swallow Feather");
        set("aliases", ({ "feather", "barn swallow feather", "swallow feather" }));
        set("blueprint", "barn swallow feather");
    }
}

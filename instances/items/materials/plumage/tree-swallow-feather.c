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
        set("name", "Tree Swallow Feather");
        set("short", "Tree Swallow Feather");
        set("aliases", ({ "feather", "tree swallow feather", "swallow feather" }));
        set("blueprint", "tree swallow feather");
    }
}

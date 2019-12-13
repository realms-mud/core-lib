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
        set("name", "Hippogriff Hair");
        set("short", "Hippogriff Hair");
        set("aliases", ({ "hair", "hippogriff hair" }));
        set("blueprint", "hippogriff hair");
    }
}

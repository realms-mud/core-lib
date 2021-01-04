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
        set("name", "Horse Hair");
        set("short", "Horse Hair");
        set("aliases", ({ "hair", "horse hair" }));
        set("blueprint", "horse hair");
    }
}

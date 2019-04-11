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
        set("name", "Pegasus Hair");
        set("short", "Pegasus Hair");
        set("aliases", ({ "hair", "pegasus hair" }));
        set("blueprint", "pegasus hair");
    }
}

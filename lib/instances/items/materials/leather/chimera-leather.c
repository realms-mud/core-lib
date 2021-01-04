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
        set("name", "Chimera leather");
        set("short", "Chimera leather");
        set("aliases", ({ "leather", "chimera leather" }));
        set("blueprint", "chimera leather");
    }
}

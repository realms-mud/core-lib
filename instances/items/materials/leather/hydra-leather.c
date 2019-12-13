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
        set("name", "Hydra leather");
        set("short", "Hydra leather");
        set("aliases", ({ "leather", "hydra leather" }));
        set("blueprint", "hydra leather");
    }
}

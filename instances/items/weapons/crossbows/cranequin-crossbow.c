//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Cranequin crossbow");
        set("short", "Cranequin crossbow");
        set("aliases", ({ "crossbow", "cranequin crossbow" }));
        set("blueprint", "cranequin crossbow");
    }
}

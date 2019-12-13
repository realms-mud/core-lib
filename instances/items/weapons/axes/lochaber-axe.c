//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Lochaber axe");
        set("short", "Lochaber axe");
        set("aliases", ({ "axe", "lochaber axe" }));
        set("blueprint", "lochaber axe");
    }
}

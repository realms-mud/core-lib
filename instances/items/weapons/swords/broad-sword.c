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
        set("name", "Broad sword");
        set("short", "Broad sword");
        set("aliases", ({ "sword", "broadsword", "broad sword" }));
        set("blueprint", "broad sword");
    }
}

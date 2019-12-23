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
        set("name", "Double bit axe");
        set("short", "Double bit axe");
        set("aliases", ({ "axe", "double bit axe" }));
        set("blueprint", "double bit axe");
    }
}

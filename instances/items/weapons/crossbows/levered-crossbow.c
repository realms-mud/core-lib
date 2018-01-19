//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Levered crossbow");
        set("short", "Levered crossbow");
        set("aliases", ({ "crossbow" }));
        set("blueprint", "levered crossbow");
    }
}

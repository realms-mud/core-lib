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
        set("name", "Lucerne hammer");
        set("short", "Lucerne hammer");
        set("aliases", ({ "hammer" }));
        set("blueprint", "lucerne hammer");
    }
}

//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Bastard sword");
        set("short", "Bastard sword");
        set("aliases", ({ "sword", "bastardsword" }));
        set("blueprint", "bastard sword");
    }
}

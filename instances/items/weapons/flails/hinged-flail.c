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
        set("name", "Hinged flail");
        set("short", "Hinged flail");
        set("aliases", ({ "flail", "hinged flail" }));
        set("blueprint", "hinged flail");
    }
}

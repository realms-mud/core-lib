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
        set("name", "Quarterstaff");
        set("short", "Quarterstaff");
        set("aliases", ({ "staff", "quarterstaff" }));
        set("blueprint", "quarterstaff");
    }
}

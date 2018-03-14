//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Jeddart staff");
        set("short", "Jeddart staff");
        set("aliases", ({ "staff", "jeddart staff" }));
        set("blueprint", "jeddart staff");
    }
}

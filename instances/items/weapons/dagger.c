//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
// 10/10/2017 - Valren
//    ** Created generic standard weapon
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Dagger");
        set("short", "Dagger");
        set("long", "It has a short blade that is only as long as the "
            "hilt. Its blade is about six inches long (.2 meters).");
        set("blueprint", "dagger");
    }
}

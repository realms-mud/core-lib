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
        set("name", "Great sword");
        set("short", "Great sword");
        set("aliases", ({ "sword", "two-handed sword", "greatsword" }));
        set("blueprint", "great sword");
    }
}

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
        set("name", "Long sword");
        set("short", "Long sword");
        set("aliases", ({ "sword", "longsword" }));
        set("long", "It is a stout-bladed weapon with a blade about four feet long.");
        set("blueprint", "long sword");
    }
}

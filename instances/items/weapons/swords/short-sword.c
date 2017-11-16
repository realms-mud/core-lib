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
        set("name", "Short sword");
        set("short", "Short sword");
        set("aliases", ({ "sword", "shortsword" }));
        set("long", "It is a stout-bladed weapon with a blade about two feet long.");
        set("blueprint", "short sword");
    }
}

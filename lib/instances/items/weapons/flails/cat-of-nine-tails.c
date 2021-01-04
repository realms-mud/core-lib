//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Cat of nine tails");
        set("short", "Cat of nine tails");
        set("aliases", ({ "flail", "cat of nine tails" }));
        set("blueprint", "cat of nine tails");
    }
}

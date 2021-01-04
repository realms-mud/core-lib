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
        set("name", "Sparth axe");
        set("short", "Sparth axe");
        set("aliases", ({ "axe", "sparth axe" }));
        set("blueprint", "sparth axe");
    }
}

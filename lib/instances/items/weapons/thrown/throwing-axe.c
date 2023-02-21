//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Throwing axe");
    set("short", "Throwing axe");
    set("aliases", ({ "axe", "throwing axe" }));
    set("blueprint", "throwing axe");
}

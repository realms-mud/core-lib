//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Splitting maul");
    set("short", "Splitting maul");
    set("aliases", ({ "axe", "maul", "splitting maul" }));
    set("blueprint", "splitting maul");
}

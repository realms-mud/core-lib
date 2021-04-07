//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Lochaber axe");
    set("short", "Lochaber axe");
    set("aliases", ({ "axe", "lochaber axe" }));
    set("blueprint", "lochaber axe");
}

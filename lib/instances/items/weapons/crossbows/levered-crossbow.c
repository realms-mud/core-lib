//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Levered crossbow");
    set("short", "Levered crossbow");
    set("aliases", ({ "crossbow", "levered crossbow" }));
    set("blueprint", "levered crossbow");
}

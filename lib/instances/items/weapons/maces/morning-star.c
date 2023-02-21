//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Morning star");
    set("short", "Morning star");
    set("aliases", ({ "mace", "morningstar", "morning star" }));
    set("blueprint", "morning star");
}

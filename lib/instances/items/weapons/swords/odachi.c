//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Odachi");
    set("short", "Odachi");
    set("aliases", ({ "sword", "two-handed sword", "odachi" }));
    set("blueprint", "odachi");
}

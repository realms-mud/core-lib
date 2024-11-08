//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Katar");
    set("short", "Katar");
    set("aliases", ({ "claws", "dagger", "katar" }));
    set("blueprint", "katar");
}

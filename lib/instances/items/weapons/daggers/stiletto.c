//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Stiletto");
    set("short", "Stiletto");
    set("aliases", ({ "dagger", "stiletto" }));
    set("blueprint", "stiletto");
}

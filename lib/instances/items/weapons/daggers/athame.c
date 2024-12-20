//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Athame");
    set("short", "Athame");
    set("long", "It has a short blade that is only as long as the "
        "hilt. Its blade is about six inches long (.2 meters).");
    set("aliases", ({ "dagger" }));
    set("blueprint", "athame");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Rosewood Seed");
    set("short", "Rosewood Seed");
    set("aliases", ({ "rosewood seed", "seed" }));
    set("blueprint", "rosewood seed");
}

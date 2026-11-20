//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("blueprint", "pumpkin");
    set("name", "pumpkin");
    set("short", "a small pumpkin");
    set("aliases", ({ "pumpkin", "pumpkins" }));
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Linden Flower");
    set("short", "Linden Flower");
    set("aliases", ({ "linden flower", "linden", "flower" }));
    set("blueprint", "linden flower");
}

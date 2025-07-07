//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Wheat Bread");
    set("short", "Wheat Bread");
    set("aliases", ({ "wheat bread", "bread", "loaf" }));
    set("blueprint", "wheat bread");
}

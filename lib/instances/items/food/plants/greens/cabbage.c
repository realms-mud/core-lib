//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("blueprint", "cabbage");
    set("name", "cabbage");
    set("short", "a cabbage");
    set("aliases", ({ "cabbage", "cabbages" }));
}

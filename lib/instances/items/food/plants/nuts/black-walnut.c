//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Black Walnut");
    set("short", "Black Walnut");
    set("aliases", ({ "black walnut", "walnut", "nut" }));
    set("blueprint", "black walnut");
}

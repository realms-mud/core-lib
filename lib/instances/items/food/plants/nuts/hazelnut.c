//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Hazelnut");
    set("short", "Hazelnut");
    set("aliases", ({ "hazelnut", "nut" }));
    set("blueprint", "hazelnut");
}

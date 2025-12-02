//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sweet Red Pepper");
    set("short", "Sweet Red Pepper");
    set("aliases", ({ "pepper", "sweet pepper", "red pepper", "sweet red pepper" }));
    set("blueprint", "sweet red pepper");
}

//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Green Pepper");
    set("short", "Green Pepper");
    set("aliases", ({ "pepper", "green pepper" }));
    set("blueprint", "green pepper");
}

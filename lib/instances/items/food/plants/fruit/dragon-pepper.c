//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Dragon Pepper");
    set("short", "Dragon Pepper");
    set("aliases", ({ "pepper", "dragon pepper" }));
    set("blueprint", "dragon pepper");
}

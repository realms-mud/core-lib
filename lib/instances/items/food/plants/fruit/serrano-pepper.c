//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Serrano Pepper");
    set("short", "Serrano Pepper");
    set("aliases", ({ "pepper", "serrano", "serrano pepper" }));
    set("blueprint", "serrano pepper");
}

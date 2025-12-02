//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cortland Apple");
    set("short", "Cortland Apple");
    set("aliases", ({ "cortland apple", "apple" }));
    set("blueprint", "cortland apple");
}

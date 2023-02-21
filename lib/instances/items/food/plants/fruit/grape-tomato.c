//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Grape Tomato");
    set("short", "Grape Tomato");
    set("aliases", ({ "grape tomato", "tomato" }));
    set("blueprint", "grape tomato");
}

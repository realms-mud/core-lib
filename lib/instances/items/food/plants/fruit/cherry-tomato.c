//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cherry Tomato");
    set("short", "Cherry Tomato");
    set("aliases", ({ "cherry tomato", "tomato" }));
    set("blueprint", "cherry tomato");
}

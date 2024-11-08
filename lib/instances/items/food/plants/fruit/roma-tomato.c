//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Roma Tomato");
    set("short", "Roma Tomato");
    set("aliases", ({ "roma tomato", "tomato" }));
    set("blueprint", "roma tomato");
}

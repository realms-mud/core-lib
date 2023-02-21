//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Red Potato");
    set("short", "Red Potato");
    set("aliases", ({ "red potato", "potato" }));
    set("blueprint", "red potato");
}

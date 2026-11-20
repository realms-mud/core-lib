//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("blueprint", "raspberry");
    set("name", "raspberry");
    set("short", "a raspberry");
    set("aliases", ({ "raspberry", "raspberries" }));
}

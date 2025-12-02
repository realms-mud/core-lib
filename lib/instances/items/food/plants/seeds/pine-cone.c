//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Pine Cone");
    set("short", "Pine Cone");
    set("aliases", ({ "pine cone", "cone" }));
    set("blueprint", "pine cone");
}

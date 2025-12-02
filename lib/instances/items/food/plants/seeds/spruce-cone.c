//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Spruce Cone");
    set("short", "Spruce Cone");
    set("aliases", ({ "spruce cone", "cone" }));
    set("blueprint", "spruce cone");
}

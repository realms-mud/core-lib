//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("blueprint", "kale");
    set("name", "kale");
    set("short", "some kale leaves");
    set("aliases", ({ "kale", "kale leaves" }));
}

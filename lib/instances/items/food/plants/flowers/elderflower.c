//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Elderflower");
    set("short", "Elderflower");
    set("aliases", ({ "elderflower", "elder flower", "flower" }));
    set("blueprint", "elderflower");
}

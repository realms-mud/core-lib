//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sweet Corn");
    set("short", "Sweet Corn");
    set("aliases", ({ "sweet corn", "corn" }));
    set("blueprint", "sweet corn");
}

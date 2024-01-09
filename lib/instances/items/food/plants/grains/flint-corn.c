//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Flint Corn");
    set("short", "Flint Corn");
    set("aliases", ({ "flint corn", "corn" }));
    set("blueprint", "flint corn");
}

//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Flour Corn");
    set("short", "Flour Corn");
    set("aliases", ({ "flour corn", "corn" }));
    set("blueprint", "flour corn");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Poporn");
    set("short", "Poporn");
    set("aliases", ({ "popcorn", "corn" }));
    set("blueprint", "popcorn");
}

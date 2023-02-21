//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Waxy Corn");
    set("short", "Waxy Corn");
    set("aliases", ({ "waxy corn", "corn" }));
    set("blueprint", "waxy corn");
}

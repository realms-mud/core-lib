//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cayenne Pepper");
    set("short", "Cayenne Pepper");
    set("aliases", ({ "pepper", "cayenne", "cayenne pepper" }));
    set("blueprint", "cayenne pepper");
}

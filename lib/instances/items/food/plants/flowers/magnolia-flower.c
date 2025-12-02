//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Magnolia Flower");
    set("short", "Magnolia Flower");
    set("aliases", ({ "magnolia flower", "magnolia" }));
    set("blueprint", "magnolia flower");
}

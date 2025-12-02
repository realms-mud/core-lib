//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Petite Potato");
    set("short", "Petite Potato");
    set("aliases", ({ "petite potato", "potato" }));
    set("blueprint", "petite potato");
}

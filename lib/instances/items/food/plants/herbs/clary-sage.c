//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Clary Sage");
    set("short", "Clary Sage");
    set("aliases", ({ "clary sage", "clary", "sage" }));
    set("blueprint", "clary sage");
}

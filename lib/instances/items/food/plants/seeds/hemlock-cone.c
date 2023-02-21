//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Hemlock Cone");
    set("short", "Hemlock Cone");
    set("aliases", ({ "hemlock cone", "cone" }));
    set("blueprint", "hemlock cone");
}

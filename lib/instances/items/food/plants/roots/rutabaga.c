//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Rutabaga");
    set("short", "Rutabaga");
    set("aliases", ({ "rutabaga" }));
    set("blueprint", "rutabaga");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Red Lentil");
    set("short", "Red Lentil");
    set("aliases", ({ "lentil", "red lentil" }));
    set("blueprint", "red lentil");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Long Pepper");
    set("short", "Long Pepper");
    set("aliases", ({ "pepper", "long pepper" }));
    set("blueprint", "long pepper");
}

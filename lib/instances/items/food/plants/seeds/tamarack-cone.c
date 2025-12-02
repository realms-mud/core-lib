//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tamarack Cone");
    set("short", "Tamarack Cone");
    set("aliases", ({ "tamarack cone", "cone", "conifer cone" }));
    set("blueprint", "tamarack cone");
}

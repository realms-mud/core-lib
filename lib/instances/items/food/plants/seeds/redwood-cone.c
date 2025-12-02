//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Redwood Cone");
    set("short", "Redwood Cone");
    set("aliases", ({ "redwood cone", "cone" }));
    set("blueprint", "redwood cone");
}

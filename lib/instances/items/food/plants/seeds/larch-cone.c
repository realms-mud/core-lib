//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Larch Cone");
    set("short", "Larch Cone");
    set("aliases", ({ "larch cone", "cone", "conifer cone" }));
    set("blueprint", "larch cone");
}

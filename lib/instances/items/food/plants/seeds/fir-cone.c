//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Fir Cone");
    set("short", "Fir Cone");
    set("aliases", ({ "fir cone", "cone" }));
    set("blueprint", "fir cone");
}

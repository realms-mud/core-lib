//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Snow Pea");
    set("short", "Snow Pea");
    set("aliases", ({ "pea", "snow pea" }));
    set("blueprint", "snow pea");
}

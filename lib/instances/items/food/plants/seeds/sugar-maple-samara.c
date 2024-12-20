//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sugar Maple Samara");
    set("short", "Sugar Maple Samara");
    set("aliases", ({ "sugar maple samaras", "sugar maple samara", "samaras", "samara",
        "maple samaras", "maple samara" }));
    set("blueprint", "sugar maple samara");
}

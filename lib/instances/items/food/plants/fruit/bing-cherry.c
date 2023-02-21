//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bing Cherry");
    set("short", "Bing Cherry");
    set("aliases", ({ "cherry", "bing cherry" }));
    set("blueprint", "bing cherry");
}

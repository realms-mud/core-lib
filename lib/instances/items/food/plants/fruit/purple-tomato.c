//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Purple Tomato");
    set("short", "Purple Tomato");
    set("aliases", ({ "purple tomato", "tomato" }));
    set("blueprint", "purple tomato");
}

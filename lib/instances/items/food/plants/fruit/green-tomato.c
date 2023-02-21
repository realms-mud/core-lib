//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Green Tomato");
    set("short", "Green Tomato");
    set("aliases", ({ "green tomato", "tomato" }));
    set("blueprint", "green tomato");
}

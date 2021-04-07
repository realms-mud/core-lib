//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Yellow Tomato");
    set("short", "Yellow Tomato");
    set("aliases", ({ "yellow tomato", "tomato" }));
    set("blueprint", "yellow tomato");
}

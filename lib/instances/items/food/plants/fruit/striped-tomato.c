//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Striped Tomato");
    set("short", "Striped Tomato");
    set("aliases", ({ "striped tomato", "tomato" }));
    set("blueprint", "striped tomato");
}

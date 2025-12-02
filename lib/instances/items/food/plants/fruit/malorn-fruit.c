//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Malorn Fruit");
    set("short", "Malorn Fruit");
    set("aliases", ({ "malorn fruit", "malorn" }));
    set("blueprint", "malorn fruit");
}

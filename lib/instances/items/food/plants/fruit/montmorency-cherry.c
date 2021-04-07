//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Montmorency Cherry");
    set("short", "Montmorency Cherry");
    set("aliases", ({ "cherry", "montmorency cherry" }));
    set("blueprint", "montmorency cherry");
}

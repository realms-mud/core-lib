//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Choke Cherry");
    set("short", "Choke Cherry");
    set("aliases", ({ "cherry", "choke cherry" }));
    set("blueprint", "choke cherry");
}

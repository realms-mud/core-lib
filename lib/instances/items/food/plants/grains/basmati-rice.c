//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Basmati Rice");
    set("short", "Basmati Rice");
    set("aliases", ({ "basmati rice", "rice" }));
    set("blueprint", "basmati rice");
}

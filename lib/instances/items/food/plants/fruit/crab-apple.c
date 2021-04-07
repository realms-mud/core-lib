//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Crabapple");
    set("short", "Crabapple");
    set("aliases", ({ "crabapple", "apple" }));
    set("blueprint", "crabapple");
}

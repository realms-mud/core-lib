//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Chickpea");
    set("short", "Chickpea");
    set("aliases", ({ "pea", "chick pea", "chickpea", "garbanzo bean", "garbanzo" }));
    set("blueprint", "chickpea");
}

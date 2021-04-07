//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Buckwheat");
    set("short", "Buckwheat");
    set("aliases", ({ "buckwheat" }));
    set("blueprint", "buckwheat");
}

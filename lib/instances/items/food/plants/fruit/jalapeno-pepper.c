//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Jalapeno Pepper");
    set("short", "Jalapeno Pepper");
    set("aliases", ({ "pepper", "jalapeno", "jalapeno pepper" }));
    set("blueprint", "jalapeno pepper");
}

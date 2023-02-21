//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Striped Maize");
    set("short", "Striped Maize");
    set("aliases", ({ "striped maize", "maize", "corn" }));
    set("blueprint", "striped maize");
}

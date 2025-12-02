//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Black Peppercorn");
    set("short", "Black Peppercorn");
    set("aliases", ({ "peppercorn", "pepper", "black pepper" }));
    set("blueprint", "black peppercorn");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Kolsche Beer");
    set("short", "Kolsche Beer");
    set("biological effect", "alcohol");
    set("biological strength", 1);
    set("aliases", ({ "kolsche", "beer" }));
    set("blueprint", "kolsche beer");
}

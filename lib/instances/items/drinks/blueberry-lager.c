//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Blueberry Lager");
    set("short", "Blueberry Lager");
    set("biological effect", "alcohol");
    set("biological strength", 1);
    set("aliases", ({ "blueberry lager", "beer", "lager" }));
    set("blueprint", "blueberry lager");
}

//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Trippel Beer");
    set("short", "Trippel Beer");
    set("biological effect", "alcohol");
    set("biological strength", 3);
    set("aliases", ({ "trippel", "beer" }));
    set("blueprint", "trippel beer");
}

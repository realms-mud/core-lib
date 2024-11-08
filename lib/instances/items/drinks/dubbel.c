//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Dubbel Beer");
    set("short", "Dubbel Beer");
    set("biological effect", "alcohol");
    set("biological strength", 2);
    set("aliases", ({ "dubbel", "beer", "dubbel beer" }));
    set("blueprint", "dubbel beer");
}

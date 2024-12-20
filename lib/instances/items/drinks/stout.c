//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Stout Beer");
    set("short", "Stout Beer");
    set("biological effect", "alcohol");
    set("biological strength", 2);
    set("aliases", ({ "stout", "beer" }));
    set("blueprint", "stout beer");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bock Beer");
    set("short", "Bock Beer");
    set("biological effect", "alcohol");
    set("biological strength", 1);
    set("aliases", ({ "bock", "beer" }));
    set("blueprint", "bock beer");
}

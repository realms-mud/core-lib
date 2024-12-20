//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Dubbel Pale Ale");
    set("short", "Dubbel Pale Ale");
    set("biological effect", "alcohol");
    set("biological strength", 2);
    set("aliases", ({ "dubbel", "beer", "pale ale", "ale" }));
    set("blueprint", "dubbel pale ale");
}

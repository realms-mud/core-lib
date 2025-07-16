//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cherry Lambic Ale");
    set("short", "Cherry Lambic Ale");
    set("biological effect", "alcohol");
    set("biological strength", 1);
    set("aliases", ({ "cherry lambic", "beer", "lambic", "ale" }));
    set("blueprint", "cherry lambic ale");
}

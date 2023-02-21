//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Raspberry Lambic Ale");
    set("short", "Raspberry Lambic Ale");
    set("biological effect", "alcohol");
    set("biological strength", 1);
    set("aliases", ({ "raspberry lambic", "beer", "lambic", "ale" }));
    set("blueprint", "raspberry lambic ale");
}

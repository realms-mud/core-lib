//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Pilsner Beer");
    set("short", "Pilsner Beer");
    set("biological effect", "alcohol");
    set("biological strength", 1);
    set("aliases", ({ "pilsner", "beer" }));
    set("blueprint", "pilsner beer");
}

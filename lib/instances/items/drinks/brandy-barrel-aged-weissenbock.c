//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Brandy Barrel Aged Weissenbock");
    set("short", "Brandy Barrel Aged Weissenbock");
    set("biological effect", "alcohol");
    set("biological strength", 3);
    set("aliases", ({ "weissenbock", "beer", "lager", "barrel aged weissenbock" }));
    set("blueprint", "brandy barrel aged weissenbock");
}

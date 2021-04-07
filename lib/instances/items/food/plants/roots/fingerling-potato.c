//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Fingerling Potato");
    set("short", "Fingerling Potato");
    set("aliases", ({ "fingerling potato", "potato" }));
    set("blueprint", "fingerling potato");
}

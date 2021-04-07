//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Evil Resistance");
    set("short", "Potion of Evil Resistance");
    set("aliases", ({ "evil resistance", "potion", "evil resistance potion",
        "potion of evil resistance" }));
    set("blueprint", "evil resistance potion");
}

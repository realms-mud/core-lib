//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Silver ore");
    set("short", "Silver ore");
    set("aliases", ({ "ore", "silver ore", "silver" }));
    set("blueprint", "silver ore");
}

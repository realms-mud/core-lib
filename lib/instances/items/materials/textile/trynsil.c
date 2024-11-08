//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Trynsil");
    set("short", "Trynsil");
    set("aliases", ({ "cloth", "textile", "trynsil" }));
    set("blueprint", "trynsil");
}

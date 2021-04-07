//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cherry");
    set("short", "Cherry (Wood)");
    set("aliases", ({ "wood", "cherry" }));
    set("blueprint", "cherry");
}

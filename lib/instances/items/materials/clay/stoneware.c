//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Stoneware");
    set("short", "Stoneware");
    set("aliases", ({ "clay", "stoneware" }));
    set("blueprint", "stoneware");
}

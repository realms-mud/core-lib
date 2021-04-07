//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Dolomite");
    set("short", "Dolomite");
    set("aliases", ({ "stone", "dolomite" }));
    set("blueprint", "dolomite");
}

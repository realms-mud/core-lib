//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Buckthorn");
    set("short", "Buckthorn");
    set("aliases", ({ "wood", "buckthorn" }));
    set("blueprint", "buckthorn");
}

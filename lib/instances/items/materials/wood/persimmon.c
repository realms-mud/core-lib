//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Persimmon");
    set("short", "Persimmon (Wood)");
    set("aliases", ({ "wood", "persimmon" }));
    set("blueprint", "persimmon");
}

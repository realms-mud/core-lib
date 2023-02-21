//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Apricot");
    set("short", "Apricot (Wood)");
    set("aliases", ({ "wood", "apricot" }));
    set("blueprint", "apricot");
}

//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Gauntlets");
    set("short", "Gauntlets");
    set("aliases", ({ "gauntlets" }));
    set("blueprint", "gauntlets");
}

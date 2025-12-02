//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "War scythe");
    set("short", "War scythe");
    set("aliases", ({ "scythe", "war scythe" }));
    set("blueprint", "war scythe");
}

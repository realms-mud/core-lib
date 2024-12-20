//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/corpse.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("short", "The corpse of Haldor");
    set("corpse", "haldor");
    set("aliases", ({ "haldor", "corpse of haldor", "corpse" }));
}

//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/corpse.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("short", "Black-robed corpse with an arrow protruding from its "
        "throat");
    set("corpse", "black-robed figure");
    set("aliases", ({ "black-robed corpse", "corpse" }));
}

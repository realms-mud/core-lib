//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/corpse.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        set("short", "Black-robed corpse with an arrow protruding from its "
            "throat");
        set("corpse", "black-robed figure");
        set("aliases", ({ "black-robed corpse", "corpse" }));
    }
}

//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/corpse.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        set("short", "The corpse of Haldor");
        set("corpse", "haldor");
        set("aliases", ({ "haldor", "corpse of haldor", "corpse" }));
    }
}

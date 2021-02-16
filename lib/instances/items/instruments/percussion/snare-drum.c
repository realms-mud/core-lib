//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "snare drum");
        set("short", "snare drum");
        set("aliases", ({ "snare drum", "drum", "snare",
            "percussion", "instrument" }));
        set("blueprint", "snare drum");
    }
}

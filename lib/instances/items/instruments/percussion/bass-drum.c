//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "bass drum");
    set("short", "bass drum");
    set("aliases", ({ "bass drum", "drum", "bass", "percussion", 
        "instrument" }));
    set("blueprint", "bass drum");
}

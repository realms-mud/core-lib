//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Horn");
    set("short", "Horn");
    set("aliases", ({ "horn", "windcap", "wind cap", "instrument" }));
    set("blueprint", "horn");
}

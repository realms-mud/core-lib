//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cornett");
    set("short", "Cornett");
    set("aliases", ({ "cornett", "windcap", "wind cap", "instrument" }));
    set("blueprint", "cornett");
}

//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Oboe");
    set("short", "Oboe");
    set("aliases", ({ "oboe", "windcap", "wind cap", "instrument" }));
    set("blueprint", "oboe");
}

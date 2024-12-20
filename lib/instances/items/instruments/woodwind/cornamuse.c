//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cornamuse");
    set("short", "Cornamuse");
    set("aliases", ({ "cornamuse", "windcap", "wind cap", "instrument" }));
    set("blueprint", "cornamuse");
}

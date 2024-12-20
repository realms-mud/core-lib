//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Rebec");
    set("short", "Rebec");
    set("aliases", ({ "rebec", "strings", "instrument" }));
    set("blueprint", "rebec");
}

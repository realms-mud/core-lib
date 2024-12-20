//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "12-String Guitar");
    set("short", "12-String Guitar");
    set("aliases", ({ "12-string guitar", "12 string", "12 string guitar",
        "guitar", "strings", "instrument" }));
    set("blueprint", "12-string guitar");
}

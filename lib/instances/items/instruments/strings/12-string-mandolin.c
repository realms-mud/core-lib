//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "12-String Mandolin");
    set("short", "12-String Mandolin");
    set("aliases", ({ "12-string mandolin", "mandolin", "12 string mandolin",
        "strings", "instrument" }));
    set("blueprint", "12-string mandolin");
}

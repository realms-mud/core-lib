//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bass Viol");
    set("short", "Bass Viol");
    set("aliases", ({ "bass viol", "viol", "bass", "strings", "instrument" }));
    set("blueprint", "bass viol");
}

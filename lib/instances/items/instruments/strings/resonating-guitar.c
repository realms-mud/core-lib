//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Resonating Guitar");
    set("short", "Resonating Guitar");
    set("aliases", ({ "resonating guitar", "guitar", "strings", "instrument" }));
    set("blueprint", "resonating guitar");
}

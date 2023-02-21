//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Guitar");
    set("short", "Guitar");
    set("aliases", ({ "guitar", "strings", "instrument" }));
    set("blueprint", "guitar");
}

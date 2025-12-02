//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bodhran");
    set("short", "Bodhran");
    set("aliases", ({ "bodhran", "drum", "percussion", "instrument" }));
    set("blueprint", "bodhran");
}

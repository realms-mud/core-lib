//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Archlute");
    set("short", "Archlute");
    set("aliases", ({ "archlute", "lute", "strings", "instrument" }));
    set("blueprint", "archlute");
}

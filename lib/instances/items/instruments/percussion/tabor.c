//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tabor");
    set("short", "Tabor");
    set("aliases", ({ "tabor", "drum", "percussion", "instrument" }));
    set("blueprint", "tabor");
}

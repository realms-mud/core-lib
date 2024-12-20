//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tuba");
    set("short", "Tuba");
    set("aliases", ({ "tuba", "brass", "wind cap", "instrument" }));
    set("blueprint", "tuba");
}

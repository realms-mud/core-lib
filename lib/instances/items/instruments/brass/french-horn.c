//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "French Horn");
    set("short", "French Horn");
    set("aliases", ({ "french horn", "brass", "horn", "wind cap", "instrument" }));
    set("blueprint", "french horn");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bugle");
    set("short", "Bugle");
    set("aliases", ({ "bugle", "brass", "wind cap", "instrument" }));
    set("blueprint", "bugle");
}

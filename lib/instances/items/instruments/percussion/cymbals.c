//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cymbals");
    set("short", "Cymbals");
    set("aliases", ({ "cymbals", "cymbal", "percussion", "instrument" }));
    set("blueprint", "cymbals");
}

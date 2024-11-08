//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Shagbut");
    set("short", "Shagbut");
    set("aliases", ({ "shagbut", "windcap", "wind cap", "instrument" }));
    set("blueprint", "shagbut");
}

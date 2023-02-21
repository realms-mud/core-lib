//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Crumhorn");
    set("short", "Crumhorn");
    set("aliases", ({ "crumhorn", "windcap", "wind cap", "instrument" }));
    set("blueprint", "crumhorn");
}

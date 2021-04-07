//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Gamba");
    set("short", "Gamba");
    set("aliases", ({ "gamba", "viol", "strings", "instrument" }));
    set("blueprint", "gamba");
}

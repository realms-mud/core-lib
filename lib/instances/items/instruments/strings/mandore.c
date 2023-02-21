//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mandore");
    set("short", "Mandore");
    set("aliases", ({ "mandore", "strings", "instrument" }));
    set("blueprint", "mandore");
}

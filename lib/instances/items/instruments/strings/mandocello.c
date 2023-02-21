//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mandocello");
    set("short", "Mandocello");
    set("aliases", ({ "mandocello", "strings", "instrument" }));
    set("blueprint", "mandocello");
}

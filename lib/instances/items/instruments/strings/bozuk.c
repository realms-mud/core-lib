//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bozuk");
    set("short", "Bozuk");
    set("aliases", ({ "bozuk", "strings", "instrument" }));
    set("blueprint", "bozuk");
}

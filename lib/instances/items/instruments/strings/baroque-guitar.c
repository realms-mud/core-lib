//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Baroque Guitar");
    set("short", "Baroque Guitar");
    set("aliases", ({ "baroque guitar", "guitar", "strings", "instrument" }));
    set("blueprint", "baroque guitar");
}

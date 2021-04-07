//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bagpipes");
    set("short", "Bagpipes");
    set("aliases", ({ "bagpipes", "pipes" }));
    set("blueprint", "bagpipes");
}

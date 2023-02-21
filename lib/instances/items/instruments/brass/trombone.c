//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Trombone");
    set("short", "Trombone");
    set("aliases", ({ "trombone", "brass", "wind cap", "instrument" }));
    set("blueprint", "trombone");
}

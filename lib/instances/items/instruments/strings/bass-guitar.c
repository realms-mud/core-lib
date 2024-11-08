//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bass Guitar");
    set("short", "Bass Guitar");
    set("aliases", ({ "bass guitar", "guitar", "strings", "instrument" }));
    set("blueprint", "bass guitar");
}

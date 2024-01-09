//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Hurdy-gurdy");
    set("short", "Hurdy-gurdy");
    set("aliases", ({ "hurdy-gurdy", "hurdy gurdy", "hurdy", "gurdy", "strings", "instrument" }));
    set("blueprint", "hurdy-gurdy");
}

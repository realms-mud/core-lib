//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Padded arm greaves");
    set("short", "Padded arm greaves");
    set("aliases", ({ "arm greaves", "greaves", "padded arm greaves", "padded greaves" }));
    set("blueprint", "padded arm greaves");
}

//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cittern");
    set("short", "Cittern");
    set("aliases", ({ "cittern", "strings", "instrument" }));
    set("blueprint", "cittern");
}

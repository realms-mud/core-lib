//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Adufe");
    set("short", "Adufe");
    set("aliases", ({ "adufe", "drum", "percussion", "instrument" }));
    set("blueprint", "adufe");
}

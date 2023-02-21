//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Nakers");
    set("short", "Nakers");
    set("aliases", ({ "nakers", "drum", "drums", "percussion", 
        "instrument" }));
    set("blueprint", "nakers");
}

//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Nakers");
        set("short", "Nakers");
        set("aliases", ({ "nakers", "drum", "drums", "percussion", 
            "instrument" }));
        set("blueprint", "nakers");
    }
}

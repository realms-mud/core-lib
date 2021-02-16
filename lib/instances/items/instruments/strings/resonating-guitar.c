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
        set("name", "Resonating Guitar");
        set("short", "Resonating Guitar");
        set("aliases", ({ "resonating guitar", "guitar", "strings", "instrument" }));
        set("blueprint", "resonating guitar");
    }
}

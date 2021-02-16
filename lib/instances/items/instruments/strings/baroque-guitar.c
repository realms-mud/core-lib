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
        set("name", "Baroque Guitar");
        set("short", "Baroque Guitar");
        set("aliases", ({ "baroque guitar", "guitar", "strings", "instrument" }));
        set("blueprint", "baroque guitar");
    }
}

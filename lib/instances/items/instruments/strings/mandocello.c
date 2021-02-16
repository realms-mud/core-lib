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
        set("name", "Mandocello");
        set("short", "Mandocello");
        set("aliases", ({ "mandocello", "strings", "instrument" }));
        set("blueprint", "mandocello");
    }
}

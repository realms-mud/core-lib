//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Shawm");
        set("short", "Shawm");
        set("aliases", ({ "shawm", "windcap", "wind cap", "instrument" }));
        set("blueprint", "shawm");
    }
}

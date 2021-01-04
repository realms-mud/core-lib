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
        set("name", "Cornamuse");
        set("short", "Cornamuse");
        set("aliases", ({ "cornamuse", "windcap", "wind cap", "instrument" }));
        set("blueprint", "cornamuse");
    }
}

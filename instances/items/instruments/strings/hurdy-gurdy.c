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
        set("name", "Hurdy-gurdy");
        set("short", "Hurdy-gurdy");
        set("aliases", ({ "hurdy-gurdy", "hurdy gurdy", "hurdy", "gurdy", "strings", "instrument" }));
        set("blueprint", "hurdy-gurdy");
    }
}

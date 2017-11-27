//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Padded arm greaves");
        set("short", "Padded arm greaves");
        set("aliases", ({ "arm greaves", "greaves" }));
        set("blueprint", "padded arm greaves");
    }
}

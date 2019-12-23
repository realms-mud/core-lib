//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Plate arm greaves");
        set("short", "Plate arm greaves");
        set("aliases", ({ "greaves", "arm greaves", "plate arm greaves", "plate greaves" }));
        set("blueprint", "plate arm greaves");
    }
}

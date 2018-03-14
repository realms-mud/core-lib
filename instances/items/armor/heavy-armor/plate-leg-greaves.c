//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Plate leg greaves");
        set("short", "Plate leg greaves");
        set("aliases", ({ "greaves", "leg greaves", "plate leg greaves" }));
        set("blueprint", "plate leg greaves");
    }
}

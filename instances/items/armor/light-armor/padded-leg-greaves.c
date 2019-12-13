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
        set("name", "Padded leg greaves");
        set("short", "Padded leg greaves");
        set("aliases", ({ "leg greaves", "greaves", "padded leg greaves", "padded greaves" }));
        set("blueprint", "padded leg greaves");

    }
}

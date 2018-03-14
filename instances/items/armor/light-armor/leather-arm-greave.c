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
        set("name", "Leather arm greaves");
        set("short", "Leather arm greaves");
        set("aliases", ({ "arm greaves", "greaves", "leather greaves", "leather arm greaves" }));
        set("blueprint", "leather arm greaves");
    }
}

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
        set("name", "Leather jacket");
        set("short", "Leather jacket");
        set("aliases", ({ "leather", "jacket" }));
        set("blueprint", "leather jacket");
    }
}

//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Pale Ale");
        set("short", "Pale Ale");
        set("aliases", ({ "pale ale", "ale", "beer" }));
        set("blueprint", "pale ale");
    }
}

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
        set("name", "Dubbel Pale Ale");
        set("short", "Dubbel Pale Ale");
        set("aliases", ({ "dubbel", "beer", "pale ale", "ale" }));
        set("blueprint", "dubbel pale ale");
    }
}

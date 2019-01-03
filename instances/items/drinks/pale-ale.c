//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        set("biological effect", "alcohol");
        set("biological strength", 1);
        set("aliases", ({ "pale ale", "ale", "beer" }));
        set("blueprint", "pale ale");
    }
}

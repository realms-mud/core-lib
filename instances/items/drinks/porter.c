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
        set("name", "Porter Beer");
        set("short", "Porter Beer");
        set("biological effect", "alcohol");
        set("biological strength", 1);
        set("aliases", ({ "porter", "beer" }));
        set("blueprint", "porter beer");
    }
}

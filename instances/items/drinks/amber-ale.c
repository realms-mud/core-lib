//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Amber Ale");
        set("short", "Amber Ale");
        set("biological effect", "alcohol");
        set("biological strength", 1);
        set("aliases", ({ "amber", "beer", "ale" }));
        set("blueprint", "amber ale");
    }
}

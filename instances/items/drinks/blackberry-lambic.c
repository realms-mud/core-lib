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
        set("name", "Blackberry Lambic Ale");
        set("short", "Blackberry Lambic Ale");
        set("aliases", ({ "blackberry lambic", "beer", "lambic", "ale" }));
        set("blueprint", "blackberry lambic ale");
    }
}

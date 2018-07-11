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
        set("name", "Cherry Lambic Ale");
        set("short", "Cherry Lambic Ale");
        set("aliases", ({ "cherry lambic", "beer", "lambic", "ale" }));
        set("blueprint", "cherry lambic ale");
    }
}

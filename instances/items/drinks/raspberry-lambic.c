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
        set("name", "Raspberry Lambic Ale");
        set("short", "Raspberry Lambic Ale");
        set("aliases", ({ "raspberry lambic", "beer", "lambic", "ale" }));
        set("blueprint", "raspberry lambic ale");
    }
}

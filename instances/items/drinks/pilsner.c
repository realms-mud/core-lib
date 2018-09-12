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
        set("name", "Pilsner Beer");
        set("short", "Pilsner Beer");
        set("biological effect", "alcohol");
        set("biological strength", 1);
        set("aliases", ({ "pilsner", "beer" }));
        set("blueprint", "pilsner beer");
    }
}

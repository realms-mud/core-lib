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
        set("name", "Test Pilsner Beer");
        set("short", "Test Pilsner Beer");
        set("aliases", ({ "pilsner", "beer", "pilsner beer" }));
        set("blueprint", "pilsner beer");
    }
}

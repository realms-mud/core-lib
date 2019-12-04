//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Cypress Cone");
        set("short", "Cypress Cone");
        set("aliases", ({ "cypress cone", "cone" }));
        set("blueprint", "cypress cone");
    }
}

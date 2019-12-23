//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Redwood Cone");
        set("short", "Redwood Cone");
        set("aliases", ({ "redwood cone", "cone" }));
        set("blueprint", "redwood cone");
    }
}

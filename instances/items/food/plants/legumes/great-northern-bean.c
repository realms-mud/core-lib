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
        set("name", "Great Northern Bean");
        set("short", "Great Northern Bean");
        set("aliases", ({ "bean", "great northern bean", "northern bean" }));
        set("blueprint", "great northern bean");
    }
}

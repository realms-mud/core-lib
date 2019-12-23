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
        set("name", "Cannellini Bean");
        set("short", "Cannellini Bean");
        set("aliases", ({ "bean", "cannellini bean", "cannellini" }));
        set("blueprint", "cannellini bean");
    }
}

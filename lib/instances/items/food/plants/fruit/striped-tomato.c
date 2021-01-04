//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Striped Tomato");
        set("short", "Striped Tomato");
        set("aliases", ({ "striped tomato", "tomato" }));
        set("blueprint", "striped tomato");
    }
}

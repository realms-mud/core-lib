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
        set("name", "Yellow Tomato");
        set("short", "Yellow Tomato");
        set("aliases", ({ "yellow tomato", "tomato" }));
        set("blueprint", "yellow tomato");
    }
}

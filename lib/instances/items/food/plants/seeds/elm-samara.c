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
        set("name", "Elm Samara");
        set("short", "Elm Samara");
        set("aliases", ({ "elm samaras", "elm samara", "samaras", "samara" }));
        set("blueprint", "elm samara");
    }
}

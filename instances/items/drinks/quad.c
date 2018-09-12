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
        set("name", "Quad Beer");
        set("short", "Quad Beer");
        set("biological effect", "alcohol");
        set("biological strength", 3);
        set("aliases", ({ "quad", "beer" }));
        set("blueprint", "quad beer");
    }
}

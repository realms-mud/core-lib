//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/drink.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Serendipitous Lambic Ale");
        set("short", "Serendipitous Lambic Ale");
        set("biological effect", "alcohol");
        set("biological strength", 1);
        set("aliases", ({ "serendipitous lambic", "beer", "lambic", "ale" }));
        set("blueprint", "serendipitous lambic ale");
    }
}

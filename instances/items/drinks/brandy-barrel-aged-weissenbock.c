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
        set("name", "Brandy Barrel Aged Weissenbock");
        set("short", "Brandy Barrel Aged Weissenbock");
        set("aliases", ({ "weissenbock", "beer", "lager", "barrel aged weissenbock" }));
        set("blueprint", "brandy barrel aged weissenbock");
    }
}

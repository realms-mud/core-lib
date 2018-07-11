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
        set("name", "Milk Stout Beer");
        set("short", "Milk Stout Beer");
        set("aliases", ({ "milk stout", "beer", "stout" }));
        set("blueprint", "milk stout beer");
    }
}

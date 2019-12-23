//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Tincture of Combat Prowess");
        set("short", "Tincture of Combat Prowess");
        set("aliases", ({ "tincture", "potion", "combat prowess",
            "tincture of combat prowess" }));
        set("blueprint", "tincture of combat prowess");
    }
}

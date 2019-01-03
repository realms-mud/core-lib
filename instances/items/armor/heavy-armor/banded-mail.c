//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Banded mail");
        set("short", "Banded mail");
        set("aliases", ({ "armor", "mail", "banded mail" }));
        set("blueprint", "banded mail");
    }
}

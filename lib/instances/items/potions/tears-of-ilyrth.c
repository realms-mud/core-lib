//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tears of Ilyrth");
    set("short", "Tears of Ilyrth");
    set("aliases", ({ "tears", "potion", "ilyrth potion", "ilyrth" }));
    set("blueprint", "tears of ilyrth");
}

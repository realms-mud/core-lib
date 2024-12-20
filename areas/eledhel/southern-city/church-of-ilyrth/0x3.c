//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/opulent-entry.c");
    addItem("/lib/environment/items/lighting/window.c", "west");

    addExitWithDoor("south", "/areas/eledhel/southern-city/12x5.c");
}

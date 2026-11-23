//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    setShortDescription("The guarded landing at Eledhel's northern docks");
    addFeature("/lib/environment/features/water/ocean.c", "east");
    addItem("/lib/environment/items/marine/mooring-post.c", "north");
    addItem("/lib/environment/items/marine/cargo-net.c", "south");
    addDecorator("dock");
    addObject("/areas/eledhel/northern-city/characters/north-dockmaster.c");
    addExit("west", "/areas/eledhel/northern-city/23x8.c");
    addExit("south", "/areas/eledhel/northern-city/24x7.c");
}

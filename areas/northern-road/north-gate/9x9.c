//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southwest");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/north-gate/9x8.c");
    addExit("south", "/areas/eledhel/estates/erator/grounds/0x0.c");
}

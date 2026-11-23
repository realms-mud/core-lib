//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southwest");
    setEncounterLevel(2);
    addRandomCreature(({ "red fox", "outlaw", "ruffian" }));

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/north-gate/0x6.c");
    addExit("south", "/areas/northern-road/north-gate/0x8.c");
}

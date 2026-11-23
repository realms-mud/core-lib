//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "south");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southeast");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    setEncounterLevel(5);
    addRandomCreature(({ "gray wolf", "outlaw", "ruffian" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/5x6.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/3x6.c");
}

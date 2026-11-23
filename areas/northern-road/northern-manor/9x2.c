//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "south");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southeast");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox", "white-tail deer" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/northern-manor/10x2.c");
    addExit("west", "/areas/northern-road/northern-manor/8x2.c");
}

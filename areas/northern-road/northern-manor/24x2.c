//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/stream.c", "south");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "east");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southeast");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox", "white-tail deer" }));

    addDecorator("village road corner NW");

    addExit("north", "/areas/northern-road/northern-manor/24x1.c");
    addExit("west", "/areas/northern-road/northern-manor/23x2.c");
}

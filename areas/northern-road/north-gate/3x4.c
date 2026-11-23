//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/oak-stand.c", "northwest");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "south");
    setEncounterLevel(2);
    addRandomCreature(({ "red fox", "outlaw", "ruffian" }));

    addDecorator("village road T-north");

    addExit("north", "/areas/northern-road/north-gate/3x3.c");
    addExit("east", "/areas/northern-road/north-gate/4x4.c");
    addExit("west", "/areas/northern-road/north-gate/2x4.c");
}

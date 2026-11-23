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
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "north");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox", "outlaw", "ruffian" }));

    addDecorator("village east-west road");

    addExit("east",
        "/areas/eledhel/estates/kirin/approach/second/3x0.c");
    addExit("west",
        "/areas/eledhel/estates/kirin/approach/second/1x0.c");
}

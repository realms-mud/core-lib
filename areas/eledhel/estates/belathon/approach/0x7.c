//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/sandy-shoreline.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox", "white-tail deer", "outlaw" }));

    addDecorator("village north-south road");

    addExit("north",
        "/areas/eledhel/estates/belathon/approach/0x8.c");
    addExit("south",
        "/areas/eledhel/estates/belathon/approach/0x6.c");
}

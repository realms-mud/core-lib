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
    addFeature("/lib/environment/features/trees/alder-stand.c", "south");
    setEncounterLevel(5);
    addRandomCreature(({ "red fox", "white-tail deer", "outlaw" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/15x4.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/13x4.c");
}

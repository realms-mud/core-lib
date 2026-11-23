//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/rye-field.c", "north");
    setEncounterLevel(5);
    addRandomCreature(({ "red fox", "white-tail deer", "outlaw" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/8x2.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/6x2.c");
}

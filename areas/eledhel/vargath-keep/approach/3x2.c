//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("The sentry post guards the track with two ballistae");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/military/ballista.c", "north");
    addItem("/lib/environment/items/military/ballista.c", "south");
    addExit("west", "/areas/eledhel/vargath-keep/approach/2x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/approach/4x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/approach/3x1.c");
    addRandomCreature(({ "outlaw", "ruffian" }));
}

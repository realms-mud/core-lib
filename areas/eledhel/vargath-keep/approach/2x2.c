//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("A shallow gully meets the track below the outpost");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("west", "/areas/eledhel/vargath-keep/approach/1x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/approach/3x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/approach/2x1.c");
    addRandomCreature(({ "outlaw", "ruffian", "timber wolf" }));
}

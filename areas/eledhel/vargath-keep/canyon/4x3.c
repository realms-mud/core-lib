//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-west");
    setShortDescription("A narrow shelf follows the Hallenach downstream");
    addFeature("/lib/environment/features/water/canyon-river.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/3x3.c");
    addExit("north", "/areas/eledhel/vargath-keep/canyon/4x2.c");
    addRandomCreature(({ "outlaw", "timber wolf" }));
}

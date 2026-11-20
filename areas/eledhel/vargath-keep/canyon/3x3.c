//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("A rough shelter protects the foundry workers");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/2x3.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/4x3.c");
    addExit("north", "/areas/eledhel/vargath-keep/canyon/3x2.c");
    addRandomCreature(({ "outlaw", "ruffian" }));
}

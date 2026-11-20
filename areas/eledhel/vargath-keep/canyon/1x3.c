//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-east");
    setShortDescription("A cluster of low shelters sits below the west wall");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/vargath-keep/canyon/1x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/2x3.c");
    addRandomCreature(({ "outlaw", "ruffian" }));
}

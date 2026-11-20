//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south");
    setShortDescription("A lookout platform in a wind-bent pine");
    addFeature("/lib/environment/features/trees/pine-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/eledhel/vargath-keep/approach/3x2.c");
    addRandomCreature(({ "outlaw" }));
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "north");
    addFeature("/lib/environment/features/water/river.c", "north");
    addFeature("/lib/environment/features/trees/buckthorn-stand.c", "north");

    addExit("north", "/areas/eledhel/west-rural/20x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/west-rural/20x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"hunter","outlaw","keeper of the night","red wolf"}));
}

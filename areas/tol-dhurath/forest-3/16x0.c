//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "west");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "east");

    addExit("north", "/areas/tol-dhurath/forest-3/16x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"hunter","outlaw","white-tail deer","red wolf"}));
}

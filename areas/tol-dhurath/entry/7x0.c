//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "west");
    addFeature("/lib/environment/features/trees/chokecherry-stand.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("east", "/areas/tol-dhurath/entry/8x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","outlaw","gray fox"}));
}

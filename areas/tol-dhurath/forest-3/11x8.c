//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "west");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "east");
    addFeature("/lib/environment/features/landforms/hollow.c", "southwest");

    addExit("west", "/areas/tol-dhurath/forest-3/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","outlaw","boar","brown bear"}));
}

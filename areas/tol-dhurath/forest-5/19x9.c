//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "north");
    addFeature("/lib/environment/features/landforms/hollow.c", "north");
    addFeature("/lib/environment/features/landforms/glen.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-5/18x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","outlaw","skunk","red squirrel"}));
}

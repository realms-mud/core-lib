//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-hill.c");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addExit("south", "/areas/tol-dhurath/northern-trail/20x3.c");
    addExit("west", "/areas/tol-dhurath/northern-trail/19x4.c");

    addRandomCreature(({"white-tail deer","outlaw","red fox"}));
}

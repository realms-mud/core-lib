//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-hill.c");
    addFeature("/lib/environment/features/landforms/hill.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addExit("south", "/areas/tol-dhurath/northern-trail/20x2.c");
    addExit("north", "/areas/tol-dhurath/northern-trail/20x4.c");

    addRandomCreature(({"hunter","wolf","outlaw"}));
}

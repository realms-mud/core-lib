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

    addExit("west", "/areas/tol-dhurath/northern-trail/2x4.c");
    addExit("east", "/areas/tol-dhurath/northern-trail/4x4.c");
    addExit("north", "/areas/tol-dhurath/northern-trail/3x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"hunter","outlaw","white-tail deer"}));
}

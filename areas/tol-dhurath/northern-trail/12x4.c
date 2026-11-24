//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-hill.c");
    addFeature("/lib/environment/features/landforms/hill.c", "north");

    addExit("west", "/areas/tol-dhurath/northern-trail/11x4.c");
    addExit("east", "/areas/tol-dhurath/northern-trail/13x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"outlaw","ruffian","gray fox"}));
}

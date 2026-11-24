//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-hill.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "north");
    addFeature("/lib/environment/features/cave.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addExit("west", "/areas/tol-dhurath/northern-trail/5x4.c");
    addExit("east", "/areas/tol-dhurath/northern-trail/7x4.c");
    addExit("north", "/areas/tol-dhurath/northern-trail/6x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"badger","outlaw","gray fox"}));
}

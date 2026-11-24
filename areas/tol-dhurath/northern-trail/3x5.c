//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-hill.c");
    addFeature(
        "/areas/tol-dhurath/northern-trail/features/sea-overlook.c",
        "north");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");

    addExit("south", "/areas/tol-dhurath/northern-trail/3x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

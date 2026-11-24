//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "north");
    addItem(
        "/areas/tol-dhurath/northern-trail/items/hrondil-milestone.c",
        "east");

    addExit("west", "/areas/tol-dhurath/northern-trail/9x4.c");
    addExit("east", "/areas/tol-dhurath/northern-trail/11x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

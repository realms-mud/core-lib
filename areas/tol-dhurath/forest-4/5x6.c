//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "southeast");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southeast");

    addExit("east", "/areas/tol-dhurath/forest-4/6x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"black bear","hunter","mule deer","outlaw"}));
}

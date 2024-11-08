//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "northeast");
    addFeature("/lib/environment/features/landforms/hill.c", "southwest");

    addExit("east", "/areas/tol-dhurath/temple-exterior/24x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"black bear","outlaw","panther","white-tail deer"}));
}

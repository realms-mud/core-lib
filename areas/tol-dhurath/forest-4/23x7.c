//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/hill.c", "southwest");

    addExit("east", "/areas/tol-dhurath/forest-4/24x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"weasel","outlaw","otter","coyote","red squirrel","mink","raccoon"}));
}

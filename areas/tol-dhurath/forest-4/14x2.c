//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "northeast");
    addFeature("/lib/environment/features/water/gulley-creek.c", "northeast");

    addExit("north", "/areas/tol-dhurath/forest-4/14x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"muskrat","otter","beaver","white-tail deer","raccoon","skeleton"}));
}

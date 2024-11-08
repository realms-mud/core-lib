//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "southwest");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "northeast");

    addExit("north", "/areas/tol-dhurath/forest-1/21x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"ruffian","outlaw","muskrat","coyote"}));
}

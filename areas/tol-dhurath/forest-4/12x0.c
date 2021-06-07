//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "northeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-4/13x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"weasel","zombie","ruffian","otter","white-tail deer"}));
}

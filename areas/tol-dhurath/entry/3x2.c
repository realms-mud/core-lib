//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northeast");
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");

    addExit("east", "/areas/tol-dhurath/entry/4x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"hunter","red fox","white-tail deer"}));
}

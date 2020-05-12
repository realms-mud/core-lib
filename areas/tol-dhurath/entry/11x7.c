//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("north", "/areas/tol-dhurath/entry/11x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"hunter","ruffian","outlaw","timber wolf"}));
}

//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/promontory.c", "northeast");
    addFeature("/lib/environment/features/landforms/mound.c", "east");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "south");

    addExit("south", "/areas/tol-dhurath/forest-3/18x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"hunter","mule deer","coyote"}));
}

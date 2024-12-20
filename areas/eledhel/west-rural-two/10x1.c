//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "north");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "north");

    addExit("south", "/areas/eledhel/west-rural-two/10x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"groundhog","muskrat","coyote"}));
}

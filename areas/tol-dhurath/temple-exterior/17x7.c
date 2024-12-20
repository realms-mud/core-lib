//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/stream.c", "east");
    addFeature("/lib/environment/features/landforms/bluff.c", "northeast");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");

    addExit("south", "/areas/tol-dhurath/temple-exterior/17x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/temple-exterior/18x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"mule deer","ruffian","boar","white-tail deer"}));
}

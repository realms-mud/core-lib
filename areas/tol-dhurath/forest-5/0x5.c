//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northwest");
    addFeature("/lib/environment/features/water/pond.c", "northwest");

    addExit("north", "/areas/tol-dhurath/forest-5/0x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-5/0x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"muskrat","hunter","opossum","boar","white-tail deer","chipmunk"}));
}

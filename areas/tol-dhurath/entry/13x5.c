//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/lake-shore-bluff.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("north", "/areas/tol-dhurath/entry/13x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"keeper of the night","outlaw","red fox"}));
}

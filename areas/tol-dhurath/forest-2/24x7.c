//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("south", "/areas/tol-dhurath/forest-2/24x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"gray fox","ruffian","keeper of the night","outlaw","coyote","skeleton","white-tail deer"}));
}

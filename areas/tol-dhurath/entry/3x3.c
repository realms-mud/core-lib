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

    addExit("west", "/areas/tol-dhurath/entry/2x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","hunter","coyote","white-tail deer"}));
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/crag.c", "west");
    addFeature("/lib/environment/features/water/gulley-creek.c", "east");

    addExit("south", "/areas/tol-dhurath/entry/12x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"outlaw","red fox","white-tail deer"}));
}

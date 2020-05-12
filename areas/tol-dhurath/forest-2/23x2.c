//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "southwest");

    addExit("west", "/areas/tol-dhurath/forest-2/22x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"zombie","black bear","red fox","coyote","brown bear","white-tail deer"}));
}

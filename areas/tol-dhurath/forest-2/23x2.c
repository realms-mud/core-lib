//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "northwest");

    addExit("west", "/areas/tol-dhurath/forest-2/22x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"red fox","coyote","white-tail deer"}));
}

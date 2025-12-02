//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "west");
    addFeature("/lib/environment/features/landforms/glen.c", "east");

    addExit("south", "/areas/tol-dhurath/temple-exterior/9x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"black bear","outlaw","coyote","white-tail deer","red wolf"}));
}

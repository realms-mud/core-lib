//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "north");
    addFeature("/lib/environment/features/water/gulley-creek.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-2/2x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","outlaw","white-tail deer","gray squirrel"}));
}

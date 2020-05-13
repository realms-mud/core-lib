//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "southwest");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");
    addFeature("/lib/environment/features/trees/apple-stand.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-3/0x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","outlaw","coyote","opossum"}));
}

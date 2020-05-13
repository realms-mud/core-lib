//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "south");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-2/7x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","weasel","outlaw","red fox","coyote","white-tail deer"}));
}

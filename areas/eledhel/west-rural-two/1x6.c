//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "northeast");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northeast");

    addExit("south", "/areas/eledhel/west-rural-two/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"black bear","ruffian","outlaw","beaver","gray squirrel"}));
}

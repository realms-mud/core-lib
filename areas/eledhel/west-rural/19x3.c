//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "south");
    addFeature("/lib/environment/features/trees/montmorency-cherry-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");

    addExit("east", "/areas/eledhel/west-rural/20x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"zombie","porcupine","outlaw","panther","groundhog","mink"}));
}

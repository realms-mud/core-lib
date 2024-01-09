//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");
    addFeature("/lib/environment/features/landforms/hollow.c", "northeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-3/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-3/6x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","hunter","coyote","white-tail deer","kit fox"}));
}

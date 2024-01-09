//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "west");
    addFeature("/lib/environment/features/landforms/crag.c", "west");

    addExit("north", "/areas/eledhel/west-rural/20x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/west-rural/19x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"otter","skunk","boar","skeleton"}));
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "west");
    addFeature("/lib/environment/features/landforms/hill.c", "west");

    addExit("north", "/areas/eledhel/west-rural/15x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/west-rural/14x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"zombie","mule deer","keeper of the night","raccoon","red squirrel","kit fox"}));
}

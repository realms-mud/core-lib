//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");
    addFeature("/lib/environment/features/landforms/hollow.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("south", "/areas/tol-dhurath/forest-1/0x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-2/24x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","hunter","outlaw","beaver"}));
}

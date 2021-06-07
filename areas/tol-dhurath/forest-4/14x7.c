//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "north");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-4/13x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"beaver","knight of the storm","outlaw","chipmunk"}));
}

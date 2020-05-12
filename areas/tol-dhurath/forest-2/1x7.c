//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/bluff.c", "northeast");
    addFeature("/lib/environment/features/trees/honeycrisp-apple-stand.c", "northeast");

    addExit("north", "/areas/tol-dhurath/forest-2/1x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-2/1x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"boar","knight of the storm","outlaw"}));
}

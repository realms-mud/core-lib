//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "south");
    addFeature("/lib/environment/features/landforms/hill.c", "south");
    addFeature("/lib/environment/features/trees/crabapple-stand.c", "south");

    addExit("north", "/areas/eledhel/west-rural/2x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"keeper of the night","knight of the storm","warg","mink","chipmunk"}));
}

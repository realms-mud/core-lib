//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "south");
    addFeature("/lib/environment/features/landforms/glen.c", "south");

    addExit("south", "/areas/tol-dhurath/forest-1/10x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"black bear","ruffian","knight of the storm","keeper of the night","white-tail deer","gray wolf"}));
}

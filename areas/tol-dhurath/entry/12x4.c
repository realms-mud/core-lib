//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/crag.c", "west");
    addFeature("/lib/environment/features/water/gulley-creek.c", "west");

    addExit("south", "/areas/tol-dhurath/entry/12x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"keeper of the night","warg","outlaw","timber wolf","white-tail deer","wolverine"}));
}

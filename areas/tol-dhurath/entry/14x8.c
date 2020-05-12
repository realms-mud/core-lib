//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pear-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/crag.c", "southeast");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "southeast");

    addExit("north", "/areas/tol-dhurath/entry/14x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/entry/13x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

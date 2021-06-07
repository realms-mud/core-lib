//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "northwest");
    addFeature("/lib/environment/features/trees/willow-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/combe.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-5/7x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-5/6x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

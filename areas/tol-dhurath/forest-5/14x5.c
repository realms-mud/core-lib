//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southeast");
    addFeature("/lib/environment/features/landforms/knoll.c", "southeast");
    addFeature("/lib/environment/features/water/brook.c", "southeast");

    addExit("west", "/areas/tol-dhurath/forest-5/13x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-5/14x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

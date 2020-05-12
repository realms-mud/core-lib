//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "west");
    addFeature("/lib/environment/features/landforms/glen.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "west");

    addExit("east", "/areas/tol-dhurath/forest-2/21x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-2/20x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

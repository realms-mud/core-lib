//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "east");
    addFeature("/lib/environment/features/landforms/glen.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("east", "/areas/tol-dhurath/forest-2/21x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-2/20x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

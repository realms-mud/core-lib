//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "northeast");
    addFeature("/lib/environment/features/landforms/glen.c", "northeast");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-2/21x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-2/20x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

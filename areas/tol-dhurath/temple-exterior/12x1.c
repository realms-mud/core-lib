//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "northwest");

    addExit("south", "/areas/tol-dhurath/temple-exterior/12x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/temple-exterior/13x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/valley.c", "west");

    addExit("west", "/areas/tol-dhurath/temple-exterior/23x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/temple-exterior/24x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

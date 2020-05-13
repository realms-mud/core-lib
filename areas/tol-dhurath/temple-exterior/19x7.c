//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northeast");
    addFeature("/lib/environment/features/landforms/mound.c", "northwest");

    addExit("north", "/areas/tol-dhurath/temple-exterior/19x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/temple-exterior/20x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

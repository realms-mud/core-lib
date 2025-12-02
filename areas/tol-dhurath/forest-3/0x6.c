//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addFeature("/lib/environment/features/landforms/crag.c", "northeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-3/0x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-3/1x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

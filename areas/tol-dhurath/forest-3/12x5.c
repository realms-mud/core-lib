//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/yew-stand.c", "north");
    addFeature("/lib/environment/features/landforms/combe.c", "northwest");
    addFeature("/lib/environment/features/landforms/mound.c", "west");

    addExit("east", "/areas/tol-dhurath/forest-3/13x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-3/12x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

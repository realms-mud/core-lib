//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "north");
    addFeature("/lib/environment/features/water/pond.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-2/15x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"raccoon","red fox","outlaw"}));
}

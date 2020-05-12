//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "southeast");
    addFeature("/lib/environment/features/water/pond.c", "southeast");

    addExit("north", "/areas/tol-dhurath/forest-2/15x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"timber wolf","red fox","outlaw"}));
}

//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "east");
    addFeature("/lib/environment/features/landforms/mound.c", "southwest");

    addExit("east", "/areas/tol-dhurath/temple-exterior/14x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/temple-exterior/13x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"ruffian","gray fox","red fox"}));
}

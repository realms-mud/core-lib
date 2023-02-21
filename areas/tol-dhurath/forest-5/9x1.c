//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hummock.c", "northwest");
    addFeature("/lib/environment/features/landforms/tor.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-5/9x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"coyote","timber wolf","boar","mink"}));
}

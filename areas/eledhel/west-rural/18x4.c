//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southwest");
    addFeature("/lib/environment/features/water/pond.c", "southwest");
    addFeature("/lib/environment/features/water/stream.c", "southwest");

    addExit("south", "/players/maeglin/regstuff/18x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/players/maeglin/regstuff/19x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "northwest");

    addExit("east", "/players/maeglin/regstuff/16x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/players/maeglin/regstuff/15x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}


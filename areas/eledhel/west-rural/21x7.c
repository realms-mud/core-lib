//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "east");

    addExit("east", "/players/maeglin/regstuff/22x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/players/maeglin/regstuff/21x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}


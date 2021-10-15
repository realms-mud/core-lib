//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "north");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "north");

    addExit("south", "/players/maeglin/regstuff/5x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/players/maeglin/regstuff/6x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}


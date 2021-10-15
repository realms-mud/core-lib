//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gorge-creek.c", "northeast");

    addExit("south", "/players/maeglin/regstuff/1x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/players/maeglin/regstuff/2x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}


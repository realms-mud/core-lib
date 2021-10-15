//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "northeast");

    addExit("east", "/players/maeglin/regstuff/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/players/maeglin/regstuff/9x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

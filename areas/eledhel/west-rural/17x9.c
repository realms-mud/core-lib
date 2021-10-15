//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northeast");
    addFeature("/lib/environment/features/landforms/ridge.c", "northeast");

    addExit("east", "/players/maeglin/regstuff/18x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/players/maeglin/regstuff/16x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}


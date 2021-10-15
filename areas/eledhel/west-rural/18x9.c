//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "west");
    addFeature("/lib/environment/features/landforms/hill.c", "west");

    addExit("east", "/players/maeglin/regstuff/19x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/players/maeglin/regstuff/17x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}


//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/trees/elm-stand.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");

    addExit("south", "/players/maeglin/regstuff/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/players/maeglin/regstuff/9x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/players/maeglin/regstuff/11x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}


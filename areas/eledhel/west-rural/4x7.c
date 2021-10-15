//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "northeast");

    addExit("north", "/players/maeglin/regstuff/4x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/players/maeglin/regstuff/3x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}


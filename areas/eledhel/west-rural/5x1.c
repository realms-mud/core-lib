//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "south");

    addExit("west", "/players/maeglin/regstuff/4x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/players/maeglin/regstuff/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

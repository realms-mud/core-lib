//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "southeast");

    addExit("west", "/players/maeglin/regstuff/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/players/maeglin/regstuff/6x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

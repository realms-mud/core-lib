//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");

    addExit("south", "/players/maeglin/regstuff/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/players/maeglin/regstuff/23x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

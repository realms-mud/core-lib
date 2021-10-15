//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("east", "/players/maeglin/regstuff/8x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/players/maeglin/regstuff/7x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"black bear","ruffian","outlaw","keeper of the night","red squirrel"}));
}


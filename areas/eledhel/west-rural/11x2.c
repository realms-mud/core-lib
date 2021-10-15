//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "west");

    addExit("south", "/players/maeglin/regstuff/11x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/players/maeglin/regstuff/11x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/players/maeglin/regstuff/10x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}


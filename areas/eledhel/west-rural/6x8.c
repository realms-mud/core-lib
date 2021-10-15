//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "northwest");
    addFeature("/lib/environment/features/water/river.c", "northwest");

    addExit("west", "/players/maeglin/regstuff/5x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/players/maeglin/regstuff/6x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hillock.c", "northwest");

    addExit("south", "/players/maeglin/regstuff/6x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/players/maeglin/regstuff/6x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/players/maeglin/regstuff/5x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}


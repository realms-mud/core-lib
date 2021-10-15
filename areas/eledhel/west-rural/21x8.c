//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northeast");

    addExit("south", "/players/maeglin/regstuff/21x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/players/maeglin/regstuff/20x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}


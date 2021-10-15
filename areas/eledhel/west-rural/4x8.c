//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/red-apple-stand.c", "southwest");
    addFeature("/lib/environment/features/water/ravine-brook.c", "southwest");

    addExit("north", "/players/maeglin/regstuff/4x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/players/maeglin/regstuff/4x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}


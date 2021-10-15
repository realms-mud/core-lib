//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "south");
    addFeature("/lib/environment/features/water/canyon-brook.c", "south");

    addExit("west", "/players/maeglin/regstuff/21x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/players/maeglin/regstuff/22x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}


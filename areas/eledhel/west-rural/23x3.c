//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southeast");
    addFeature("/lib/environment/features/water/canyon-brook.c", "southeast");

    addExit("west", "/players/maeglin/regstuff/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/players/maeglin/regstuff/23x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}


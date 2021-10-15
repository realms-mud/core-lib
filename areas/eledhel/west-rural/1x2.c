//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-brook.c", "west");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");

    addExit("east", "/players/maeglin/regstuff/2x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/players/maeglin/regstuff/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

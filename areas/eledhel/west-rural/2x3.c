//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addFeature("/lib/environment/features/water/canyon-stream.c", "east");
    addFeature("/lib/environment/features/trees/maple-stand.c", "east");

    addExit("west", "/players/maeglin/regstuff/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/players/maeglin/regstuff/3x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

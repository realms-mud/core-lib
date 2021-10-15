//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northwest");
    addFeature("/lib/environment/features/water/canyon-stream.c", "northwest");
    addFeature("/lib/environment/features/landforms/glen.c", "northwest");

    addExit("east", "/players/maeglin/regstuff/11x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/players/maeglin/regstuff/10x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}


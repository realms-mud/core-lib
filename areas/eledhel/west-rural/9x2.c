//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "north");
    addFeature("/lib/environment/features/landforms/glen.c", "north");
    addFeature("/lib/environment/features/landforms/hollow.c", "north");

    addExit("west", "/players/maeglin/regstuff/8x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/players/maeglin/regstuff/10x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

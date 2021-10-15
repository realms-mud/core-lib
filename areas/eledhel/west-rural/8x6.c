//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");
    addFeature("/lib/environment/features/trees/McIntosh-apple-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");

    addExit("east", "/players/maeglin/regstuff/9x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/players/maeglin/regstuff/7x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}


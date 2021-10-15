//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/green-apple-stand.c", "south");
    addFeature("/lib/environment/features/trees/yew-stand.c", "south");

    addExit("west", "/players/maeglin/regstuff/20x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/players/maeglin/regstuff/22x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "north");
    addFeature("/lib/environment/features/trees/elm-stand.c", "north");
    addFeature("/lib/environment/features/trees/bing-cherry-stand.c", "north");

    addExit("south", "/areas/eledhel/west-rural-two/7x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/west-rural-two/7x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

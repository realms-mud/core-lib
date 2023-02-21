//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/promontory.c", "southwest");
    addFeature("/lib/environment/features/trees/elm-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "southwest");

    addExit("west", "/areas/eledhel/west-rural-two/5x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/6x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

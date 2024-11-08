//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/trees/elm-stand.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");

    addExit("south", "/areas/eledhel/west-rural/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/west-rural/9x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural/11x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

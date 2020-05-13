//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "east");
    addFeature("/lib/environment/features/water/stream.c", "north");
    addFeature("/lib/environment/features/landforms/crag.c", "south");

    addExit("west", "/areas/tol-dhurath/temple-exterior/4x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/temple-exterior/6x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

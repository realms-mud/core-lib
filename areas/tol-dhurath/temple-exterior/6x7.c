//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/trees/malorn-stand.c", "east");
    addBuilding("/lib/environment/buildings/religious/temple.c",
        "north", "/areas/tol-dhurath/temple-interior/7x3.c");

    addExit("south", "/areas/tol-dhurath/temple-exterior/6x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

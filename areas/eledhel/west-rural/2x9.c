//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southeast");
    addFeature("/lib/environment/features/trees/cedar-stand.c", "southeast");

    addExit("south", "/areas/eledhel/west-rural/2x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/west-rural/3x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-creek.c", "southeast");
    addFeature("/lib/environment/features/water/brook.c", "southeast");

    addExit("south", "/areas/eledhel/west-rural-two/15x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/eledhel/west-rural-two/15x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

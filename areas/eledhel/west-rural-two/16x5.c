//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/waterfall.c", "southeast");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "southeast");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southeast");

    addExit("north", "/areas/eledhel/west-rural-two/16x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/west-rural-two/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

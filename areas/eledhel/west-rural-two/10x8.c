//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "north");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("west", "/areas/eledhel/west-rural-two/9x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/10x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

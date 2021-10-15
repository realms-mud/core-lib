//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pear-stand.c", "southeast");
    addFeature("/lib/environment/features/water/gulley-creek.c", "southeast");

    addExit("east", "/areas/eledhel/west-rural/6x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/west-rural/5x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

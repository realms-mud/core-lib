//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "northwest");

    addExit("east", "/areas/eledhel/west-rural/10x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/west-rural/9x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

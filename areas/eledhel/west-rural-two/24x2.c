//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/promontory.c", "northeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("west", "/areas/eledhel/west-rural-two/23x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");
    addFeature("/lib/environment/features/water/ravine-creek.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("east", "/areas/eledhel/west-rural-two/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/west-rural-two/22x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

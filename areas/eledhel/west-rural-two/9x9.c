//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The gorge creek ridge");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");
    addFeature("/lib/environment/features/water/gorge-creek.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("west", "/areas/eledhel/west-rural-two/8x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural-two/10x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

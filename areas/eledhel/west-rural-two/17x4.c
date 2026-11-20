//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-west");
    setShortDescription("The crag foothold");
    addFeature("/lib/environment/features/trees/beech-stand.c", "northeast");
    addFeature("/lib/environment/features/landforms/crag.c", "northeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "northeast");

    addExit("west", "/areas/eledhel/west-rural-two/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/17x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

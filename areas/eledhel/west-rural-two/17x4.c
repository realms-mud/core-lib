//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "northeast");
    addFeature("/lib/environment/features/landforms/crag.c", "northeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "northeast");

    addExit("west", "/areas/eledhel/west-rural-two/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/17x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

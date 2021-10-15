//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hill.c", "south");

    addExit("west", "/areas/eledhel/west-rural-two/8x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural-two/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"brown bear","mule deer","coyote"}));
}

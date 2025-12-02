//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "east");

    addExit("west", "/areas/eledhel/west-rural-two/21x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"porcupine","coyote","skunk","groundhog","gray squirrel","skeleton"}));
}

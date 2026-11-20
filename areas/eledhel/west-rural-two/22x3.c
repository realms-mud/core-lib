//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail west");
    setShortDescription("The ridge's end");
    addFeature("/lib/environment/features/landforms/hill.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addExit("west", "/areas/eledhel/west-rural-two/21x3.c");

    addRandomCreature(({"porcupine", "coyote", "skunk", "groundhog",
        "gray squirrel", "skeleton"}));
}

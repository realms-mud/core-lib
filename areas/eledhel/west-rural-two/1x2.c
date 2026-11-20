//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("The dry creek fork");

    addFeature("/lib/environment/features/water/ravine-dry-creek.c",
        "southwest");
    addFeature("/lib/environment/features/trees/oak-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/aspen-stand.c",
        "southeast");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addExit("north", "/areas/eledhel/west-rural-two/1x1.c");
    addExit("west", "/areas/eledhel/west-rural-two/0x2.c");
    addExit("east", "/areas/eledhel/west-rural-two/2x2.c");

    addRandomCreature(({"coyote", "timber wolf", "hunter"}));
}

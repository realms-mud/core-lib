//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-east");
    setShortDescription("The old hollow-way");

    addFeature("/lib/environment/features/trees/cedar-stand.c", "northwest");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addExit("south", "/areas/eledhel/west-rural-two/0x1.c");
    addExit("east", "/areas/eledhel/west-rural-two/1x2.c");
    addExit("north", "/areas/eledhel/west-rural-two/0x3.c");

    addRandomCreature(({"hunter", "mule deer", "red fox"}));
}

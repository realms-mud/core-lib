//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-west");
    setShortDescription("The cedar switchback");

    addFeature("/lib/environment/features/trees/pine-stand.c", "north");
    addFeature("/lib/environment/features/trees/cedar-stand.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addExit("west", "/areas/eledhel/west-rural-two/0x0.c");
    addExit("south", "/areas/eledhel/west-rural-two/1x1.c");

    addNonCombatCreature(({"chipmunk", "gray squirrel", "white-tail deer"}));
}

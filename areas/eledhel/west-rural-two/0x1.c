//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-east");
    setShortDescription("The brookside crossing");

    addFeature("/lib/environment/features/water/ravine-brook.c", "west");
    addFeature("/lib/environment/features/landforms/hollow.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addExit("north", "/areas/eledhel/west-rural-two/0x2.c");
    addExit("south", "/areas/eledhel/west-rural-two/0x0.c");
    addExit("east", "/areas/eledhel/west-rural-two/1x1.c");

    addNonCombatCreature(({"red fox", "white-tail deer", "red squirrel"}));
}

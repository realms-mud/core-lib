//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("The western woodland gate");

    addFeature("/lib/environment/features/trees/oak-stand.c", "northwest");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addItem("/lib/environment/items/objects/milestone.c", "northwest");

    addExit("west", "/areas/eledhel/west-rural/0x0.c");
    addExit("north", "/areas/eledhel/west-rural-two/0x1.c");
    addExit("east", "/areas/eledhel/west-rural-two/1x0.c");

    addNonCombatCreature(({"red fox", "white-tail deer", "chipmunk"}));
}

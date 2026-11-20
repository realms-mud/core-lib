//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-west");
    setShortDescription("The hunter's cut-through");

    addFeature("/lib/environment/features/trees/aspen-stand.c", "northeast");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/objects/broken-cart.c", "northwest");

    addExit("north", "/areas/eledhel/west-rural-two/1x0.c");
    addExit("south", "/areas/eledhel/west-rural-two/1x2.c");
    addExit("west", "/areas/eledhel/west-rural-two/0x1.c");

    addRandomCreature(({"coyote", "hunter", "boar"}));
}

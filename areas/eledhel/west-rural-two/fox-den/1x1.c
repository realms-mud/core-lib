//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-west passage");
    setShortDescription("The quiet inner chamber");
    addFeature("/lib/environment/features/caves/root-lattice.c", "north");
    addNonCombatCreature(({"red fox"}));

    addExit("north", "/areas/eledhel/west-rural-two/fox-den/1x0.c");
    addExit("west", "/areas/eledhel/west-rural-two/fox-den/0x1.c");
}

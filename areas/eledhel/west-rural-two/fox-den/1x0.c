//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-west passage");
    setShortDescription("The narrow den passage");
    addFeature("/lib/environment/features/caves/root-lattice.c", "north");

    addExit("west", "/areas/eledhel/west-rural-two/fox-den/0x0.c");
    addExit("south", "/areas/eledhel/west-rural-two/fox-den/1x1.c");
}

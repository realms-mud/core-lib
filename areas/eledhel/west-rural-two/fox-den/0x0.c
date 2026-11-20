//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-east passage");
    setShortDescription("The root-bound entrance");
    addFeature("/lib/environment/features/caves/root-lattice.c", "north");

    addExit("up", "/areas/eledhel/west-rural-two/7x3.c");
    addExit("east", "/areas/eledhel/west-rural-two/fox-den/1x0.c");
    addExit("south", "/areas/eledhel/west-rural-two/fox-den/0x1.c");
}

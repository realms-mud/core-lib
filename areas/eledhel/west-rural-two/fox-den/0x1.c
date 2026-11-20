//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-east passage");
    setShortDescription("The dry bedding hollow");
    addFeature("/lib/environment/features/caves/root-lattice.c", "north");

    addExit("north", "/areas/eledhel/west-rural-two/fox-den/0x0.c");
    addExit("east", "/areas/eledhel/west-rural-two/fox-den/1x1.c");
}

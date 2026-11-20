//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-west passage");
    setShortDescription("The northern passage narrows");
    addFeature("/lib/environment/features/water/ravine-creek.c", "south");
    addExit("west", "/areas/evenholt/limestone-caves/0x0.c");
    addExit("south", "/areas/evenholt/limestone-caves/1x1.c");
}

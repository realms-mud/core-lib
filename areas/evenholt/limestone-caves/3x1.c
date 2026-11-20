//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-east passage");
    setShortDescription("The low crawl beneath the flowstone");
    addFeature("/lib/environment/features/water/ravine-creek.c", "south");
    addExit("south", "/areas/evenholt/limestone-caves/3x2.c");
    addExit("east", "/areas/evenholt/limestone-caves/4x1.c");
    addRandomCreature(({ "bat" }));
}

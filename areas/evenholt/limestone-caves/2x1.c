//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-west passage");
    setShortDescription("The underground lake");
    addFeature("/lib/environment/features/water/ravine-pond.c", "east");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addExit("west", "/areas/evenholt/limestone-caves/1x1.c");
    addExit("south", "/areas/evenholt/limestone-caves/2x2.c");
    addRandomCreature(({ "bat" }));
}
